#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void searchElement(Node* head, int i) {
    Node* current = head;
    int position = 1;

    while (current != nullptr && current -> data != i) {
        current = current -> next;
        position++;
    }

    if (current != nullptr) {
        cout << "Element ditemukan pada posisi ke- " << position << endl;
        cout << "Alamat memori element: " << current << endl;
    } else {
        cout << "Element tidak di temukan" << endl;
    }
}

int main() {
    Node* head = new Node{5, nullptr};
    head->next = new Node{10, nullptr};
    head->next->next = new Node{15, nullptr};
    head->next->next->next = new Node{20, nullptr};
    head->next->next->next->next = new Node{25, nullptr};
    head->next->next->next->next->next = new Node{30, nullptr};

    int value;
    cout << "Masukan nilai yang ingin di cari: ";
    cin >> value;

    searchElement(head, value);

    return 0;

}