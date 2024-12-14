#ifndef GRAPH_H
#define GRAPH_H

typedef char infotype;

struct ElmNode {
    infotype info;
    int visited;
    ElmEdge* firstEdge; 
    ElmNode* next;
};

struct ElmEdge {
    ElmNode* node;
    ElmEdge* next;
};

struct Graph {
    ElmNode* firstNode;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infotype X);
void ConnectNode(ElmNode* N1, ElmNode* N2);
void PrintInfoGraph(Graph G);

#endif
