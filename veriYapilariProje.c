#include <stdio.h>
#include <stdlib.h>

char shortMaze[] = "maze3.txt";
char longMaze[] = "maze.txt";

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

int main(){

    FILE* fp = fopen(shortMaze, "a+");
    while(fp != NULL){
        printf("Dosya Acildi\n");
    }
    printf("Dosya Acilamadi\n");

    return 0;
}