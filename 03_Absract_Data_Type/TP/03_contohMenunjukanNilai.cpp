#include <iostream>

using namespace std;

int main(){
    int a = 16;
    int* ptr;

    ptr = &a;

    cout << "Nilai dari A adalah " << a << endl;
    cout << "Alamat dari A adalah " << ptr << endl;
    cout << "Nilai yang di tunjuk pointer adalah " << *ptr << endl;
   
    return 0;
}