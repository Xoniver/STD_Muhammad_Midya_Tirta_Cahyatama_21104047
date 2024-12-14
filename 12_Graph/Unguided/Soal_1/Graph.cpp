#include "graph.h"
#include <iostream>

using namespace std;

void CreateGraph(Graph &G) {
    G.firstNode = nullptr;
}

void InsertNode(Graph &G, infotype X) {
    ElmNode* newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = nullptr;
    newNode->next = nullptr;

    if (G.firstNode == nullptr) {
        G.firstNode = newNode;
    } else {
        ElmNode* temp = G.firstNode;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void ConnectNode(ElmNode* N1, ElmNode* N2) {
    ElmEdge* newEdge = new ElmEdge;
    newEdge->node = N2;
    newEdge->next = nullptr;

    if (N1->firstEdge == nullptr) {
        N1->firstEdge = newEdge;
    } else {
        ElmEdge* temp = N1->firstEdge;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newEdge;
    }
}

void PrintInfoGraph(Graph G) {
    ElmNode* currentNode = G.firstNode;
    while (currentNode != nullptr) {
        cout << currentNode->info << " -> ";
        ElmEdge* currentEdge = currentNode->firstEdge;
        while (currentEdge != nullptr) {
            cout << currentEdge->node->info << " ";
            currentEdge = currentEdge->next;
        }
        cout << endl;
        currentNode = currentNode->next;
    }
}

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(G.firstNode, G.firstNode->next); // A - B
    ConnectNode(G.firstNode, G.firstNode->next->next); // A - C
    ConnectNode(G.firstNode->next, G.firstNode->next->next->next); // B - D
    ConnectNode(G.firstNode->next->next, G.firstNode->next->next->next); // C - D
    ConnectNode(G.firstNode->next->next->next, G.firstNode->next->next->next->next); // D - E
    ConnectNode(G.firstNode->next->next->next, G.firstNode->next->next->next->next->next); // D - F
    ConnectNode(G.firstNode->next->next->next->next, G.firstNode->next->next->next->next->next->next); // E - G
    ConnectNode(G.firstNode->next->next->next->next, G.firstNode->next->next->next->next->next->next->next); // E - H

    cout << "Informasi Graph:" << endl;
    PrintInfoGraph(G);

    return 0;
}
