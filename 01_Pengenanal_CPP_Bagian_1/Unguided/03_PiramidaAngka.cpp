#include <iostream>
using namespace std;

int main() {
    int x;

    // Input jumlah baris
    cout << "Input: ";
    cin >> x;

    cout << "Output: " << endl;

    // Looping perbaris piramida
    for (int i = x; i >= 1; i--) {

        // Print spaces sebagai "scaffolding" piramida
        for (int scaf = x; scaf > i; scaf--) {
            cout << "  ";
        }

        // Print kiri piramida
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // Print *
        cout << "* ";

        // Print kanan piramida
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    // * penutup
    for (int s = 0; s < x; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}
