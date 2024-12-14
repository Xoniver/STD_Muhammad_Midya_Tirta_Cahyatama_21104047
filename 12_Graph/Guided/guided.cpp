#include <iostream>
#include <queue>
using namespace std;

struct ElmNode;

struct ElmEdge {
    ElmNode* node;
    ElmEdge* next;
};

struct ElmNode {
    char info;
    bool visited;
    ElmEdge* firstEdge;
    ElmNode* Next;
};

struct Graph {
    ElmNode* first;
};

void CreateGraph(Graph& G) {
    G.first = NULL;
}

void insertNode(Graph& G, char x) {
    ElmNode* newNode = new ElmNode;
    newNode->info = x;
    newNode->visited = false;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;

    if (G.first == NULL) {
        G.first = newNode;
    } else {
        ElmNode* last = G.first;
        while (last->Next != NULL) {
            last = last->Next;
        }
        last->Next = newNode;
    }
}

void connectNode(ElmNode* N1, ElmNode* N2) {
    ElmEdge* newEdge = new ElmEdge;
    newEdge->node = N2;
    newEdge->next = N1->firstEdge;
    N1->firstEdge = newEdge;
}

void PrintInfoGraph(Graph G) {
    ElmNode* temp = G.first;
    while (temp != NULL) {
        cout << temp->info << ": ";
        ElmEdge* edge = temp->firstEdge;
        while (edge != NULL) {
            cout << edge->node->info << " ";
            edge = edge->next;
        }
        cout << endl;
        temp = temp->Next;
    }
}

void ResetVisited(Graph& G) {
    ElmNode* temp = G.first;
    while (temp != NULL) {
        temp->visited = false;
        temp = temp->Next;
    }
}

void PrintDFS(Graph G, ElmNode* N) {
    if (N == NULL) {
        return;
    }
    N->visited = true;
    cout << N->info << " ";
    ElmEdge* edge = N->firstEdge;
    while (edge != NULL) {
        if (!edge->node->visited) {
            PrintDFS(G, edge->node);
        }
        edge = edge->next;
    }
}

void PrintBFS(Graph G, ElmNode* N) {
    queue<ElmNode*> Q;
    Q.push(N);
    N->visited = true;
    while (!Q.empty()) {
        ElmNode* temp = Q.front();
        Q.pop();
        cout << temp->info << " ";
        ElmEdge* edge = temp->firstEdge;
        while (edge != NULL) {
            if (!edge->node->visited) {
                edge->node->visited = true;
                Q.push(edge->node);
            }
            edge = edge->next;
        }
    }
}

int main() {
    Graph G;
    CreateGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    ElmNode* A = G.first;
    ElmNode* B = A->Next;
    ElmNode* C = B->Next;
    ElmNode* D = C->Next;
    ElmNode* E = D->Next;
    ElmNode* F = E->Next;
    ElmNode* G1 = F->Next;
    ElmNode* H = G1->Next;

    connectNode(A, B);
    connectNode(A, C);
    connectNode(A, D);
    connectNode(B, E);
    connectNode(B, F);
    connectNode(C, G1);

    cout << "Graph structure:" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS Traversal:" << endl;
    ResetVisited(G);
    PrintDFS(G, A);

    cout << "\n\nBFS Traversal:" << endl;
    ResetVisited(G);
    PrintBFS(G, A);

    return 0;
}
