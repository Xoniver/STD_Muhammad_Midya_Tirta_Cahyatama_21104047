#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() { head = nullptr; }

    void insertLast(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node* temp = head;
        if (temp == nullptr) return;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        while (temp != nullptr) {
            cout << temp->data;
            if (temp->prev != nullptr) cout << " <-> ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertLast(1);
    dll.insertLast(2);
    dll.insertLast(3);
    dll.insertLast(4);

    cout << "Daftar elemen dari depan ke belakang: ";
    dll.displayForward();

    cout << "Daftar elemen dari belakang ke depan: ";
    dll.displayBackward();

    return 0;
}
