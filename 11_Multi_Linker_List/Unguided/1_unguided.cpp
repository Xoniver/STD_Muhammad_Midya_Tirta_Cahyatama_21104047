#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Proyek
struct Proyek {
    string nama;
    int durasi; // dalam bulan
    Proyek* berikut;

    Proyek(string pnama, int pdurasi) : nama(pnama), durasi(pdurasi), berikut(nullptr) {}
};

// Struktur Node untuk Pegawai
struct Pegawai {
    string nama;
    string id;
    Proyek* kepalaProyek;
    Pegawai* berikut;

    Pegawai(string pnama, string pid) : nama(pnama), id(pid), kepalaProyek(nullptr), berikut(nullptr) {}
};

// Multi Linked List untuk Pegawai dan Proyek
class DaftarPegawaiProyek {
private:
    Pegawai* kepala;

public:
    DaftarPegawaiProyek() : kepala(nullptr) {}

    void tambahPegawai(string nama, string id) {
        Pegawai* pegawaiBaru = new Pegawai(nama, id);
        pegawaiBaru->berikut = kepala;
        kepala = pegawaiBaru;
    }

    Pegawai* cariPegawai(string id) {
        Pegawai* saatIni = kepala;
        while (saatIni) {
            if (saatIni->id == id)
                return saatIni;
            saatIni = saatIni->berikut;
        }
        return nullptr;
    }

    void tambahProyekUntukPegawai(string id, string namaProyek, int durasi) {
        Pegawai* pegawai = cariPegawai(id);
        if (pegawai) {
            Proyek* proyekBaru = new Proyek(namaProyek, durasi);
            proyekBaru->berikut = pegawai->kepalaProyek;
            pegawai->kepalaProyek = proyekBaru;
        }
    }

    void hapusProyekDariPegawai(string id, string namaProyek) {
        Pegawai* pegawai = cariPegawai(id);
        if (pegawai) {
            Proyek* saatIni = pegawai->kepalaProyek;
            Proyek* sebelumnya = nullptr;

            while (saatIni) {
                if (saatIni->nama == namaProyek) {
                    if (sebelumnya)
                        sebelumnya->berikut = saatIni->berikut;
                    else
                        pegawai->kepalaProyek = saatIni->berikut;
                    delete saatIni;
                    return;
                }
                sebelumnya = saatIni;
                saatIni = saatIni->berikut;
            }
        }
    }

    void tampilkan() {
        Pegawai* saatIni = kepala;
        while (saatIni) {
            cout << "Nama Pegawai: " << saatIni->nama << ", ID: " << saatIni->id << endl;
            Proyek* proyekSaatIni = saatIni->kepalaProyek;
            while (proyekSaatIni) {
                cout << "  Nama Proyek: " << proyekSaatIni->nama << ", Durasi: " << proyekSaatIni->durasi << " bulan" << endl;
                proyekSaatIni = proyekSaatIni->berikut;
            }
            saatIni = saatIni->berikut;
        }
    }

    ~DaftarPegawaiProyek() {
        while (kepala) {
            Pegawai* temp = kepala;
            kepala = kepala->berikut;
            Proyek* kepalaProyek = temp->kepalaProyek;
            while (kepalaProyek) {
                Proyek* tempProyek = kepalaProyek;
                kepalaProyek = kepalaProyek->berikut;
                delete tempProyek;
            }
            delete temp;
        }
    }
};

int main() {
    DaftarPegawaiProyek dpList;

    // Tambahkan pegawai
    dpList.tambahPegawai("Andi", "P001");
    dpList.tambahPegawai("Budi", "P002");
    dpList.tambahPegawai("Citra", "P003");

    // Tambahkan proyek
    dpList.tambahProyekUntukPegawai("P001", "Aplikasi Mobile", 12);
    dpList.tambahProyekUntukPegawai("P002", "Sistem Akuntansi", 8);
    dpList.tambahProyekUntukPegawai("P003", "E-commerce", 10);

    // Tambahkan proyek baru
    dpList.tambahProyekUntukPegawai("P001", "Analisis Data", 6);

    // Hapus proyek
    dpList.hapusProyekDariPegawai("P001", "Aplikasi Mobile");

    // Tampilkan data
    dpList.tampilkan();

    return 0;
}
