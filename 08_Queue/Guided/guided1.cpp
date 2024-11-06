#include <iostream>
using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;
string queueTeller[5];

bool isFull() {
  if (back == maksimalQueue) {
    return true;
  } else {
    return false;
  }
}

bool isEmpty() {
  if (back == 0) {
    return true;
  } else {
    return false;
  }
}

void enqueueAntrian(string data) {
  if (isFull()) {
    cout << "Antrian penuh" << endl;
  } else {
    if (isEmpty()) {
      queueTeller[0] = data;
      front++;
      back++;
    } else {
      queueTeller[back] = data;
      back++;
    }
  }
}   


void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    for (int i = 0; i < back - 1; i++) {
      queueTeller[i] = queueTeller[i + 1];
    }
    queueTeller[back - 1] = "";
    back--;
  }
}

int countQueue() {
  return back;
}

void clearQueue() {
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    for (int i = 0; i < back; i++) {
      queueTeller[i] = "";
    }
    back = 0;
    front = 0;
  }
}

void viewQueue() {
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    for (int i = 0; i < back; i++) {
      cout << "Antrian ke-" << i + 1 << " : " << queueTeller[i] << endl;
    }
  }
}

int main() {
  enqueueAntrian("Andi");
  enqueueAntrian("Maya");
  viewQueue();
  cout << "Jumlah antrian : " << countQueue() << endl;
  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian : " << countQueue() << endl;
  clearQueue();
  viewQueue();
  cout << "Jumlah antrian : " << countQueue() << endl;
  return 0;
}