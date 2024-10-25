#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void bubbleSort(Node* head) {
    bool swapped;
    Node* current;
    Node* nextNode = nullptr;

    if (head == nullptr)
        return;

    do {
        swapped = false;
        current = head;

        while (current->next != nextNode) {
            if (current->data > current->next->data) {
                // Tukar data antara current dan next
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        nextNode = current;
    } while (swapped);
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
    Node* head = new Node{4, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{1, nullptr};

    cout << "List sebelum diurutkan: ";
    printList(head);

    bubbleSort(head);

    cout << "List setelah diurutkan: ";
    printList(head);

    return 0;
}
