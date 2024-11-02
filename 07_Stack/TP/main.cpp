#include "stack.h"
#include <iostream>
using namespace std;

void testStack(stack &S, const string &input) {
    // Masukkan setiap karakter dari string ke dalam stack dari depan ke belakang
    for (char ch : input) {
        push(S, ch);
    }

    // Cetak isi stack awal
    cout << "Output:\n";
    printInfo(S);

    // Hapus elemen dari stack hingga hanya menyisakan bagian akhir (sesuai output yang diharapkan)
    cout << "Isi stack sesudah pop:\n";
    int half_size = input.size() / 2;
    for (int i = 0; i < half_size; i++) {
        pop(S);
    }
    printInfo(S);
}

int main() {
    stack S;
    createStack(S);

    int digit_terakhir_nim = /* masukkan digit terakhir NIM Anda */;
    string input;

    // Tentukan string input berdasarkan digit terakhir NIM
    switch (digit_terakhir_nim % 4) {
        case 0: input = "IFLABJAYA"; break;
        case 1: input = "HALOBANDUNG"; break;
        case 2: input = "PERCAYADIRI"; break;
        case 3: input = "STRUKTURDATA"; break;
    }

    testStack(S, input);

    return 0;
}
