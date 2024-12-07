#include <iostream>
#include <string>
using namespace std;

// Struktur Mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef Mahasiswa infotype;
typedef struct ElmtList *address;

struct ElmtList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L) {
    L.first = nullptr;
}


address allocate(infotype data) {
    address p = new ElmtList;
    p->info = data;
    p->next = nullptr;
    return p;
}

void insertFirst(List &L, address p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}

void insertLast(List &L, address p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        address last = L.first;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = p;
    }
}

void insertAfter(address prev, address p) {
    if (prev != nullptr) {
        p->next = prev->next;
        prev->next = p;
    }
}

void printList(List L) {
    address p = L.first;
    while (p != nullptr) {
        cout << "Nama: " << p->info.nama << endl;
        cout << "NIM: " << p->info.nim << endl;
        cout << "L/P: " << p->info.jenis_kelamin << endl;
        cout << "IPK: " << p->info.ipk << endl;
        cout << endl;
        p = p->next;
    }
}

int main() {
    List L;
    createList(L);

    infotype m1 = {"Andi", "01", 'L', 3.3};
    infotype m2 = {"Bobi", "02", 'L', 3.71};
    infotype m3 = {"Cindi", "03", 'P', 3.5};
    infotype m4 = {"Danu", "04", 'L', 4.0};
    infotype m5 = {"Eli", "05", 'P', 3.4};
    infotype m6 = {"Fahmi", "06", 'L', 3.45};
    infotype m7 = {"Gita", "07", 'P', 3.75};
    infotype m8 = {"Hilmi", "08", 'P', 3.3};

    address p1 = allocate(m1);
    address p2 = allocate(m2);
    address p3 = allocate(m3);
    address p4 = allocate(m4);
    address p5 = allocate(m5);
    address p6 = allocate(m6);
    address p7 = allocate(m7);
    address p8 = allocate(m8);

    insertFirst(L, p1);
    insertLast(L, p2);
    insertLast(L, p4);
    insertAfter(p2, p3);
    insertLast(L, p5);
    insertLast(L, p6);
    insertLast(L, p7);
    insertLast(L, p8);

    cout << "Coba insert first, last dna after\n";
    printList(L);

    return 0;
}