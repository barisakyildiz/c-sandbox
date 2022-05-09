#include <stdio.h>
#include <stdlib.h>

struct edgeStr{
    int source;
    int destination;
    int weight;
    struct edgeStr* next;
};
typedef struct edgeStr EDGE;

EDGE* init(EDGE* head){
    int i = 0, source, destination, weight;
    if(head == NULL){
        EDGE* newvertex = (EDGE*)malloc(sizeof(EDGE));
        printf("Please enter the source, destination and weight values of %dth edge in [int] [int] [int] format:", ++i);
        scanf("%d %d %d", &source, &destination, &weight);
        newvertex -> destination = destination;
        newvertex -> weight = weight;
        newvertex -> source = source;
        newvertex -> next = NULL; 
        return newvertex;
    }else{
        init(head -> next);
    }
    return head;
}

int main(){
    int vertexCount, i, edgeCount;
    printf("Please enter the Vertex Count: ");
    scanf("%d", &vertexCount);
    printf("Please enter the Edge Count: ");
    scanf("%d", &edgeCount);

    EDGE* edgeHead = NULL;
    for(i = 0; i < edgeCount; i++){
        edgeHead = init(edgeHead);
    }

}

