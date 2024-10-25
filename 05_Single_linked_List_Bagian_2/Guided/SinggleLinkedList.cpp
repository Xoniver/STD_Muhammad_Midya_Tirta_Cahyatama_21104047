#include <iostream>

using namespace std;

// definisikan tipe data element dan pointer ke element
struct Element {
    int value;
    Element* next;
};

// definisikan tipe data untuk list
struct List {
    Element* first;
};

// fungsi untuk membuat list kosong
void createList(List& L) {
    L.first = NULL;
}

// fungsi untuk mengalokasikan elemnt baru
Element* alokasi(int x) {
    Element* P = new Element;
    if (P == NULL) {
        return NULL;
    } else {
        P->value = x;
        P->next = NULL;
    }
    return P;
}

// Fungsi untuk menambahkan elemen di awal list
void insertFirst(List L, Element* P) {
    P->next = L.first;
    L.first = P;
}

// fungsi untuk mencetak semua element di list
void printinfo(List L) {
    Element* P = L.first;
    while (P != NULL) {
        cout << P->value << " ";
        P = P->next;
    }
    cout << endl;
}

// fungsi untuk mencari element dengan nilai X
Element* findElement(List L, int x) {
    Element* P = L.first;
    while (P != NULL) {
        if (P->value == x) {
            return P; // element di temukan
        }
        P = P->next;
    }
    return NULL; // element tidak ditemukan
}

// fungsi untuk menghitung total nilai element di list
int countElement(List L) {
    Element* P = L.first;
    int total = 0;
    while (P != NULL) {
        total++;
        P = P->next;
    }
    return total;
}