#include <iostream>

using namespace std;
int main(){
    int x, y, z;

    // Input Jumlah angka
    cout << "Masukkan Ukuran dimensi 1: ";
    cin >> x;
    cout << "Masukkan jumlah dimensi 2: ";
    cin >> y;
    cout << "Masukkan jumlah dimensi 3: ";
    cin >> z;

    int arr[x][y][z];

    // Input angka
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                cout << "Masukkan angka ke-" << i + 1 << " baris ke-" << j + 1 << " kolom ke-" << k + 1 << ": ";
                cin >> arr[i][j][k];
            }
        }
    }
    
    // Print hasil
    cout << "Angka dalam array: " << endl;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}