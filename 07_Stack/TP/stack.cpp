#include "stack.h"
#include <iostream>
using namespace std;

void createStack(stack &S) {
    S.Top = 0;
}

bool isEmpty(stack S) {
    return S.Top == 0;
}

bool isFull(stack S) {
    return S.Top == 15;
}

void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.Top++;
        S.info[S.Top - 1] = x;
    }
}

infotype pop(stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.Top - 1];
        S.Top--;
        return x;
    }
    return '\0'; // Mengembalikan karakter null jika stack kosong
}

void printInfo(stack S) {
    for (int i = S.Top - 1; i >= 0; i--) { // Cetak dari puncak ke dasar
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void testStack(stack &S, const string &input) {
    // Masukkan setiap karakter dari string ke dalam stack dari depan ke belakang
    for (char ch : input) {
        push(S, ch);
    }

    // Cetak isi stack awal
    cout << "Output:\n";
    printInfo(S);

    // Hapus elemen dari stack hingga hanya menyisakan bagian akhir
    cout << "Isi stack sesudah pop:\n";
    int remaining_size = input.size() / 2;
    while (S.Top > remaining_size) {
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