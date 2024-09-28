#include <iostream>

using namespace std;
int main () {
    float x, y ;

    // Input bilangan
    cout << "Masukkan bilangan pertama: ";
    cin >> x;

    cout << "Masukkan bilangan kedua: ";
    cin >> y;

    // Print hasi penjumlahan, pengurangan dan perkalian
    cout << "Hasil penjumlahan: " << x + y << endl;
    cout << "Hasil pengurangan: " << x - y << endl;
    cout << "Hasil perkalian: " << x * y << endl;

    // Jika y = 0, tidak dapat mekalukan pembagian
    if (y == 0) {
        cout << "TIdak dapat melakukan pembagian dengan angka 0" << endl;
    } else {
        cout << "Hasil pembagian: " << x / y << endl;
    }

    return 0;
}