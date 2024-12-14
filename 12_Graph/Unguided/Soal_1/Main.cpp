#include "graph.h"
#include <iostream>

using namespace std;

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
