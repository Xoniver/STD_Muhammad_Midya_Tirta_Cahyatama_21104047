#include <iostream>
#include <stack>
#include <string>

using namespace std;

//fungtion untuk membalikkan kalimat
string reverseSentence(string str) {
    stack<string> s; // menampung kata
    string temp = ""; // menampung kata sementara
    string result = ""; // menampung hasil balik kalimat
    int length = str.length(); // panjang kalimat

    for (int i = 0; i < length; i++) {
        if (str[i] != ' ') { // jika bukan spasi
            temp += str[i]; // tambahkan ke temp
        } else {
            s.push(temp); // tambahkan temp ke stack
            temp = ""; // reset temp
        }
    }
    s.push(temp); // tambahkan temp ke stack

    while (!s.empty()) {
        temp = s.top(); // ambil kata dari stack
        s.pop(); // hapus kata dari stack
        result += temp + " "; // tambahkan kata ke result
    }

    return result; // kembalikan hasil
}

int main() {
    string str;
    cout << "Masukkan kalimat: ";
    getline(cin, str); // mengambil input dari pengguna

    cout << "Kalimat setelah dibalik: " << reverseSentence(str) << endl; // menampilkan hasil

    return 0;
}
