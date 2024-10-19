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

// fungsi untuk mencari node dengan nilai tertentu
bool cariNode(node* head, int key) {
    node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

// fungsi untuk menghitung panjang linked list
int panjangLinkedList(node* head) {
    int count = 0;
    node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
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

    if (cariNode(head, 20)) {
        cout << "Node dengan nilai 20 ditemukan." << endl;
    } else {
        cout << "Node tidak ditemukan" << endl;
    }

    cout << "Panjang Linked List: " << panjangLinkedList(head) << endl;
    
    return 0;
}