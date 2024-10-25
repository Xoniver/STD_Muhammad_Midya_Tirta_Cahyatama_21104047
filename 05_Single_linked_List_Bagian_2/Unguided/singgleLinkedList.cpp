#include <iostream>
#include <string>

using namespace std;

// store data mahasiswa
struct Mahasiswa {
    int NIM;
    string nama;
    Mahasiswa* next;
};

// tambah data mahasiswa ke list
void addMahasiswa(Mahasiswa*& head, int nim, const string& nama){
    Mahasiswa* newNode = new Mahasiswa();
    newNode -> NIM = nim;
    newNode -> nama = nama;
    newNode -> next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Mahasiswa* temp = head;
        while (temp -> next != nullptr) {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
    cout << "Mahasiswa dengan NIM" << nim << " teleah ditambahkan" << endl;
}

// search mahasiswa
void searchMahasiswa(Mahasiswa* head, int nim) {
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        if (temp->NIM == nim) {
            cout << "Mahasiswa ditemukan: " << temp->nama << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan" << endl;
}

int main () {
    Mahasiswa* head = nullptr;
    int pilihan, nim;
    string nama;
    do {
        cout << " Main Menu " << endl;
        cout << "---------------------" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Cari Mahasiswa" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih Opsi: " << endl;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukan NIM: ";
                cin >> nim;
                cin.ignore();
                getline(cin, nama);
                addMahasiswa(head, nim, nama);
                break;

            case 2:
                cout << "Masukan NIM yang akan dicari: ";
                cin >> nim;
                searchMahasiswa(head, nim);
                break;
            
            default:
                cout << "Opsi tidak valid, Coba lagi" << endl;
                break;
        }
    } while (pilihan != 3);

    return 0;
}
