#include <iostream>

using namespace std;
int main(){
    int x;

    // Input Jumlah angka dalam array
    cout << "Masukkan jumlah angka: ";
    cin >> x;

    int arr[x];

    // Input angka dalam array
    for (int i = 0; i < x; i++){
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> arr[i];
    }
    
    // Output angka dalam array
    cout << "Angka dalam array: ";
    for (int i = 0; i < x; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print angka ganjil
    cout << "Angka ganjil: ";
    for (int i = 0; i < x; i++){
        if (arr[i] % 2 != 0){
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    // Print angka genap
    cout << "Angka genap: ";
    for (int i = 0; i < x; i++){
        if (arr[i] % 2 == 0){
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}