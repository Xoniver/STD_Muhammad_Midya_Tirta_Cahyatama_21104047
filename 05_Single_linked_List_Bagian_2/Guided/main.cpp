#include "SinggleLinkedList.cpp"

int main () {
    Element* L;
    Element* P1, * P2, * P3, * P4, * P5 = NULL;
    createList(L);

    // alokasi dan insert data sesuai illustrasi
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    // cetak hasil
    printinfo(L);

    // mencari emelent dengan nilai 8
    Element* found = findElement(L, 8);
    if (found != NULL) {
        cout << found->data << "ditemukan dalam list" << endl;
    } else {
        cout << "Element tidak ditemukan" << endl;
    }

    // menghitung total nilai element
    int total = countElement(L);
    cout << "Total info dari kelima element adalah: " << total << endl; 

    return 0;
}