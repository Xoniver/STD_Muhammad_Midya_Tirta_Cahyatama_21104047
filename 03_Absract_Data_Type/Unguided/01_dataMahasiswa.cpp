#include <iostream>

using namespace std;

// mendifinisikan struct Data Mahasiswa
struct Mahasiswa {
    string nama;
    string NIM;
    float uts;
    float uas;
    float tugas;
    float total;
};

// Rumus nilai ahkir
float nilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main () {
    // jumlah max array
    Mahasiswa mahasiswa[10]; 
    int totalMahasiswa;

    // input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> totalMahasiswa;

    if (totalMahasiswa > 10) {
        cout << "Jumlah mahasiswa melebihi batas" << endl;
        return 0;
    }

    // loop input data mahasiswa
    for (int i = 0; i < totalMahasiswa; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mahasiswa[i].nama;
        cout << "NIM: ";
        cin >> mahasiswa[i].NIM;
        cout << "Nilai UTS: ";
        cin >> mahasiswa[i].uts;
        cout << "Nilai UAS: ";
        cin >> mahasiswa[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mahasiswa[i].tugas;

        // hitung nilai akhir
        mahasiswa[i].total = nilaiAkhir(mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].tugas);
    }

    // print data mahasiswa
    cout << "  " << endl;
    cout << "Data Mahasiswa" << endl;
    for (int i = 0; i < totalMahasiswa; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: " << mahasiswa[i].nama << endl;
        cout << "NIM: " << mahasiswa[i].NIM << endl;
        cout << "Nilai UTS: " << mahasiswa[i].uts << endl;
        cout << "Nilai UAS: " << mahasiswa[i].uas << endl;
        cout << "Nilai Tugas: " << mahasiswa[i].tugas << endl;
        cout << "Nilai Akhir: " << mahasiswa[i].total << endl;
        cout << "--------------------------------" << endl;
    }

    return 0;
}