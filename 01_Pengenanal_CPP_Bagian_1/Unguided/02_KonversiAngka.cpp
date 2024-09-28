#include <iostream>
using namespace std;

// Fungtion Konversi angka menjadi kalimat 
string konversi(int num) {
    
    // Array kalimat satuan dan puluhan
    string satuan [] = {
        "", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Sebelas", "Dua Belas",
        "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"
        };
    string puluhan [] = {
        "", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"
        };

    // Filter angka
    if (num == 0)
        return "Nol";

    else if (num < 20)
        return satuan[num];

    else if (num == 100)
        return "Seratus";

    else {
        int puluh = num / 10;
        int satu = num % 10;
        return puluhan[puluh] + " " + satuan[satu];
    }
}

// Main function
int main () {
    
    // Input angka
    int num;
    cout << "Masukkan angka: ";
    cin >> num;
    
    // Filter angka dari 0 - 100
    if (num < 0 || num > 100) {
        cout << "Angka harus diantara 0 - 100" << endl;
    } 
    else {
        // Print hasil konversi
        cout << konversi(num) << endl;
    }
    return 0;
}