#include <stdio.h>
#include <stdlib.h>

struct node{
    int vertex;
    struct node* next;
};

struct graph{
    int nVertex;
    struct node** adjlist;
};

typedef struct node NODE;
typedef struct graph GRAPH;

NODE* createNode(int vertex){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode -> vertex = vertex;
    newNode -> next = NULL;
    return newNode;
}

GRAPH* createGraph(int nVertices){
    int i;
    GRAPH* _graph = (GRAPH*)malloc(sizeof(GRAPH));
    _graph -> nVertex = nVertices;
    _graph -> adjlist = (NODE**)malloc(nVertices * sizeof(NODE*));
    for(i = 0; i < nVertices; i++){
        _graph -> adjlist[i] = NULL;
    }
    return _graph;
}

void addEdge(GRAPH* _graph, int source, int destination){
    NODE* newNode = createNode(destination);
    newNode -> next = _graph -> adjlist[source];
    _graph -> adjlist[source] = newNode;
    newNode = createNode(source);
    newNode -> next = _graph -> adjlist[destination];
    _graph -> adjlist[destination] = newNode;
}

int main(){

    GRAPH* _graph = createGraph(10);
    addEdge(_graph, 5, 3);
    printf("PROGRAM ENDED SUCCESSFULLY\n");

    return 0;
}