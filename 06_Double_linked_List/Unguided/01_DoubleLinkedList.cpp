#include <iostream>
#include <string>

using namespace std;

struct Node {
    int idBuku;
    string judulBuku;
    string penulisBuku;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int idBuku, string judulBuku, string penulisBuku) {
        Node* newNode = new Node;
        newNode->idBuku = idBuku;
        newNode->judulBuku = judulBuku;
        newNode->penulisBuku = penulisBuku;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int idBuku, string judulBuku, string penulisBuku) {
        Node* current = head;
        while (current != nullptr) {
            if (current->idBuku == idBuku) {
                current->judulBuku = judulBuku;
                current->penulisBuku = penulisBuku;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << "ID Buku: " << current->idBuku << endl;
            cout << "Judul Buku: " << current->judulBuku << endl;
            cout << "Penulis Buku: " << current->penulisBuku << endl;
            cout << endl;
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Display data" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int idBuku;
                string judulBuku;
                string penulisBuku;
                cout << "Masukan ID Buku: ";
                cin >> idBuku;
                cout << "Masukan Judul Buku: ";
                cin >> judulBuku;
                cout << "Masukan Penulis Buku: ";
                cin >> penulisBuku;
                list.push(idBuku, judulBuku, penulisBuku);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int idBuku;
                string judulBuku;
                string penulisBuku;
                cout << "Enter ID Buku: ";
                cin >> idBuku;
                cout << "Enter new Judul Buku: ";
                cin >> judulBuku;
                cout << "Enter new Penulis Buku: ";
                cin >> penulisBuku;
                bool updated = list.update(idBuku, judulBuku, penulisBuku);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.display();
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
}