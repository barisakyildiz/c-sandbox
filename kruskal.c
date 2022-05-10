#include <stdio.h>
#include <stdlib.h>

struct edgeStr{
    int source;
    int destination;
    int weight;
    struct edgeStr* next;
};
typedef struct edgeStr EDGE;

EDGE* insertEdge(EDGE* head, int destination, int weight, int source, EDGE* prev){
    if(weight < head -> weight){
        EDGE* newvertex = (EDGE*)malloc(sizeof(EDGE));
        newvertex -> weight = weight;
        newvertex -> destination = destination;
        newvertex -> source = source;
        prev -> next = newvertex;
        newvertex -> next = head;
        return newvertex;
    }else{
        insertEdge(head->next, destination, weight, source, head);
    }
    return head;
}


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
    int vertexCount, i, edgeCount, insertDestination, insertSource, insertWeight;
    EDGE* edgeHead = NULL;
    EDGE* edgePrev = NULL;
    printf("Please enter the Vertex Count: ");
    scanf("%d", &vertexCount);
    printf("Please enter the Edge Count: ");
    scanf("%d", &edgeCount);

    
    printf("Please enter the Destination of vertex to be added");
    scanf("%d", &insertDestination);
    printf("Please enter the Source of vertex to be added");
    scanf("%d", &insertSource);
    printf("Please enter the Weight of vertex to be added");
    scanf("%d", &insertWeight);

    for(i = 0; i < edgeCount; i++){
        edgeHead = init(edgeHead);
    }

    edgeHead = insertEdge(edgeHead, insertDestination, insertWeight, insertSource, edgePrev);

    

}

