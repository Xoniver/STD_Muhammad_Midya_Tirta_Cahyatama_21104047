#include <iostream>

using namespace std;
void showArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// swap isi dari dua array
void swapArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void swapPointer(int* ptrA, int* ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

}

int main() {
    int arr1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int arr2[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int a = 6;
    int b = 14;
    int* ptrA = &a;
    int* ptrB = &b;

    cout << "Array sebelum di tukar" << endl;
    cout << "Array 1" << endl;
    showArray(arr1);
    cout << " " << endl;
    cout << "Array 2" << endl;
    showArray(arr2);
    cout << " " << endl;

    swapArray(arr1, arr2, 1, 1);

    cout << "Array setelah di tukar" << endl;
    cout << "Array 1" << endl;
    showArray(arr1);
    cout << " " << endl;
    cout << "Array 2" << endl;
    showArray(arr2);
    cout << " " << endl;

    cout << "Pointer sebelum ditukar" << endl;
    cout << "Nilai a: " << *ptrA << endl;
    cout << "Nilai b: " << *ptrB << endl;

    swapPointer(ptrA, ptrB);

    cout << "Pointer setelah ditukar" << endl;
    cout << "Nilai a: " << *ptrA << endl;
    cout << "Nilai b: " << *ptrB << endl;

    return 0;
}