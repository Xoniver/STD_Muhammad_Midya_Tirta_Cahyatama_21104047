#include <iostream>
#include "list.h"

using namespace std;

void createList(List &L) {
    first(L) = nullptr;
}

address allocate(infotype x) {
    address P = new TElmtList;
    info(P) = x;
    next(P) = nullptr;

    return P;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List L) {
    address P = first(L);
    while (P != NULL) {
        cout << info(P) << ", ";
        P = next(P);
    }
    cout << endl;
}

void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteLast(List &L) {
    if (first(L) != NULL) {
        if (next(first(L)) == NULL) {
            first(L) = NULL;
        } else {
            address P = first(L);
            while (next(next(P)) != NULL) {
                P = next(P);
            }
            next(P) = NULL;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && next(Prec) != NULL) {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

address searchInfo(List L, int info) {
    address P = first(L);
    while (P != NULL) {
        if (info(P) == info) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

int main() {
    List L;
    createList(L);
    
    int nim[10];

    // Input NIM per digit
    std::cout << "Masukkan NIM per digit (10 digit)" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Digit " << i + 1 << " : ";
        std::cin >> nim[i];
    }

    // Masukkan ke dalam list menggunakan insertLast
    for (int i = 0; i < 10; i++) {
        address P = allocate(nim[i]);
        insertLast(L, P);
    }

    // Tampilkan isi list setelah NIM diinput
    std::cout << "Isi list : ";
    printInfo(L);

    // Contoh penggunaan searchInfo
    int cari;
    std::cout << "Masukkan angka yang ingin dicari: ";
    std::cin >> cari;

    address found = searchInfo(L, cari);
    if (found != NULL) {
        std::cout << "Angka " << cari << " ditemukan di dalam list." << std::endl;
    } else {
        std::cout << "Angka " << cari << " tidak ditemukan." << std::endl;
    }

    // Contoh penggunaan deleteLast
    address del;
    deleteLast(L, del);
    std::cout << "Isi list setelah deleteLast: ";
    printInfo(L);
    
    return 0;
}
