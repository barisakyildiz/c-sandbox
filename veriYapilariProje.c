#include <stdio.h>
#include <stdlib.h>

const char shortMaze[] = "maze3.txt";
const char longMaze[] = "maze.txt"; //please enter the name of the text file that contains the maze

struct graphNode{
    int vertex;
    struct graphNode* next;
};

struct graph{
    int nVertex;
    struct graphNode** adjlist;
};

struct stackNode{
    int val;
    struct stackNode* next;
};

typedef struct stackNode STACKNODE;
typedef struct graphNode GRAPHNODE;
typedef struct graph GRAPH;

GRAPH* allocateMaze(int rows, int cols){
    GRAPH* maze = createGraph(rows*cols);
    
}

GRAPHNODE* createGraphNode(int vertex){
    GRAPHNODE* newNode = (GRAPHNODE*)malloc(sizeof(GRAPHNODE));
    newNode -> vertex = vertex;
    newNode -> next = NULL;
    return newNode;
}

GRAPH* createGraph(int nVertices){
    int i;
    GRAPH* _graph = (GRAPH*)malloc(sizeof(GRAPH));
    _graph -> nVertex = nVertices;
    _graph -> adjlist = (GRAPHNODE**)malloc(nVertices * sizeof(GRAPHNODE*));
    for(i = 0; i < nVertices; i++){
        _graph -> adjlist[i] = NULL;
    }
    return _graph;
}

void addGraphEdge(GRAPH* _graph, int source, int destination){
    GRAPHNODE* newNode = createGraphNode(destination);
    newNode -> next = _graph -> adjlist[source];
    _graph -> adjlist[source] = newNode;
    newNode = createGraphNode(source);
    newNode -> next = _graph -> adjlist[destination];
    _graph -> adjlist[destination] = newNode;
}

void stackinit(STACKNODE *head, STACKNODE *end){
    head -> next = end;
    head -> val = 0;
}

void pushStack(STACKNODE *head, int n){
    STACKNODE *current = (STACKNODE*) malloc (sizeof(STACKNODE));
    current -> val = n;
    current -> next = head -> next;
    head -> next = current;
}

int popStack(STACKNODE *head){
    int pop;
    STACKNODE *current = (STACKNODE*) malloc(sizeof(STACKNODE));
    current = head -> next;
    head -> next = current -> next;
    pop = current -> val;
    free(current);
    return pop;
}

int main(){

    STACKNODE *stackHead, *stackEnd;
    FILE* fp = fopen(shortMaze, "a+");
    while(fp != NULL){
        printf("Dosya Acildi\n");

    }
    printf("Dosya Acilamadi\n");

    return 0;
}