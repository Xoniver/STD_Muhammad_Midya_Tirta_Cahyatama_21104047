#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertSorted(Node*& head, Node* newNode) {
    Node* current = head;
    Node* prev = nullptr;

    // Jika list kosong atau elemen baru lebih kecil dari head, jadikan head
    if (head == nullptr || head->data >= newNode->data) {
        newNode->next = head;
        head = newNode;
    } else {
        // Temukan posisi yang sesuai
        while (current != nullptr && current->data < newNode->data) {
            prev = current;
            current = current->next;
        }
        prev->next = newNode;
        newNode->next = current;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{3, nullptr};
    head->next->next = new Node{5, nullptr};
    head->next->next->next = new Node{7, nullptr};

    cout << "List sebelum ditambahkan elemen: ";
    printList(head);

    // Buat elemen baru
    Node* newNode = new Node{4, nullptr};

    // Masukkan elemen baru secara terurut
    insertSorted(head, newNode);

    cout << "List setelah ditambahkan elemen: ";
    printList(head);

    return 0;
}
