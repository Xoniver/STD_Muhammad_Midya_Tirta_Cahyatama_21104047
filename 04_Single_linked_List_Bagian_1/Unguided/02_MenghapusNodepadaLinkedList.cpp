#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

// fungsi tambah node di depan
void tambahDepan(node** head_ref, int value) {
    node* newNode = new node;
    newNode->data = value;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// fungsi tambah node di belakang
void tambahBelakang(node** head_ref, int value) {
    node* newNode = new node;
    node* last = *head_ref;
    newNode->data = value;
    newNode->next = nullptr;
    if (*head_ref == nullptr) {
        *head_ref = newNode;
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

// fungsi hapus node dengan nilai tertentu
void hapusNode(node** head_ref, int key) {
    node* temp = *head_ref;
    node* prev = nullptr;
    if (temp != nullptr && temp->data == key) {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        return;
    }
    prev->next = temp->next;
    delete temp;
}

// print list
void printList(node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" <<endl;
}

int main() {
    node* head = nullptr;

    tambahDepan(&head, 10);
    tambahBelakang(&head, 20);
    tambahDepan(&head, 5);
    
    cout << "Isi Linked List: ";
    printList(head);

    hapusNode(&head, 10);
    cout << "Isi Linked List setelah menghapus node dengan nilai 10: ";
    printList(head);

    return 0;
}