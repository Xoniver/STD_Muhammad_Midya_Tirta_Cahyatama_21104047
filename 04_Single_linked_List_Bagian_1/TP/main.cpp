#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List L;
    createList(L);
   
   int angka;

   std::cout << "Masukkan angka ke-1: ";
    std::cin >> angka;
    address P1 = allocate(angka);
    insertFirst(L, P1);
    std::cout << "List setelah insert angka ke-1: ";
    printInfo(L);

    std::cout << "Masukkan angka ke-2: ";
    std::cin >> angka;
    address P2 = allocate(angka);
    insertFirst(L, P2);
    std::cout << "List setelah insert angka ke-2: ";
    printInfo(L);

    std::cout << "Masukkan angka ke-3: ";
    std::cin >> angka;
    address P3 = allocate(angka);
    insertFirst(L, P3);
    std::cout << "List setelah insert angka ke-3: ";
    printInfo(L);

    return 0;
    
}