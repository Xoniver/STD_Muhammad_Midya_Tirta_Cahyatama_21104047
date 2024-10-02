#include <iostream>

using namespace std;

// Fungtion untuk mendapatkan nilai Max
int getMax(int arr[], int x){
    int max = arr[0];
    for (int i = 1; i < x; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

// Fungtion untuk mendapatkan nilai Min
int getMin(int arr[], int x){
    int min = arr[0];
    for (int i = 1; i < x; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

// Fungtion untuk mendapatkan nilai Rata-rata
float getAverage(int arr[], int x){
    float sum = 0;
    for (int i = 0; i < x; i++){
        sum += arr[i];
    }
    return sum / x;
}

// Input jumlah array
int main(){
    int ukuran;
    cout << "Masukkan jumlah angka: ";
    cin >> ukuran;

    // Buat array
    int arr[ukuran];
    cout << "Masukkan angka: " << endl;
    for (int i = 0; i < ukuran; i++){
        cout << "angka ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Print menu
    int pilihan;
    do {
        cout << " " << endl;
        cout << "-----Menu------" << endl;
        cout << "1. Nilai Max" << endl;
        cout << "2. Nilai Min" << endl;
        cout << "3. Nilai Rata-rata" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan){
            case 1:
                cout << "Max: " << getMax(arr, ukuran) << endl;
                break;
            case 2:
                cout << "Min: " << getMin(arr, ukuran) << endl;
                break;
            case 3:
                cout << "Rata-rata: " << getAverage(arr, ukuran) << endl;
                break;
            case 4:
                cout << "Have a Nice Day!" << endl;
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
                break;
        }
    } while (pilihan != 4);
}
