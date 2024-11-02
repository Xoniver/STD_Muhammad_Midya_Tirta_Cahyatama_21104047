#include <iostream>
#include <stack>
#include <string>
using namespace std;

//fungtio untuk menentukan jenis kata palindrom
bool isPalindrome(string str) {
    stack<char> s; // menampung setengah kata
    int length = str.length(); // panjang kata
    int mid = length / 2; // mencari tengah kata

    // memasukan hinggha setengah kata ke dalam stack
    for (int i = 0; i < mid; i++) {
        s.push(str[i]);
    }

    // lanjutan dari setengah kata (Jika ganjil dilewati)
    for (int i = mid + (length % 2); i < length; i++) {
        if (s.top() != str[i]) { // membandingkan setengah kata dengan kata sebenarnya
            return false;
        }
        s.pop(); // hapus kalimat dari stack
    }

    return true; // jika cocok maka palindrom
}

int main() {
    string str;
    cout << "Masukkan kata: ";
    cin >> str; // mengambil input dari pengguna

    if (isPalindrome(str)) { // pengecekan apakah palindrom atau tidak
        cout << str << " adalah palindrom" << endl; 
    } else {
        cout << str << " bukan palindrom" << endl;
    }

    return 0;
}