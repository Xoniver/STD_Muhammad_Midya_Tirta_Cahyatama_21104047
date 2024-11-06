#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    int NIM;
    Node *next;
};

Node *front = nullptr;
Node *back = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(string data, int NIM) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->NIM = NIM;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = back = newNode;
    } else {
        if (front->NIM > NIM) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            while (current->next != nullptr && current->next->NIM < NIM) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            if (current == back) {
                back = newNode;
            }
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node *temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            back = nullptr;
        }
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void printQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* current = front;
        while (current != nullptr) {
            cout << "Nama: " << current -> data << " NIM: " << current->NIM << endl;
            current = current->next;
        }
    }
}

int main() {
    int pilihan;
    do {
        cout << " " << endl;
        cout << "-----List Antrian Mahasiswa-----" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Hapus Antrian" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Hapus semua antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nama;
                int NIM;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> NIM;
                enqueueAntrian(nama, NIM);
                break;
            }
            case 2: {
                dequeueAntrian();
                break;
            }
            case 3: {
                printQueue();
                break;
            }
            case 4: {
                clearQueue();
                break;
            }
            case 5: {
                cout << "Program selesai" << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        } 

    } while (pilihan != 5);
    return 0;
}