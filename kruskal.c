#include <stdio.h>
#include <stdlib.h>

struct edgeStr{
    int source;
    int destination;
    int weight;
    struct edgeStr* next;
};
typedef struct edgeStr EDGE;

int* kruskalMST(EDGE* head, int vertexCount1){
    int i = 0, flagk = 0, flagl = 0, totalCost = 0;
    int* traced = (int*)malloc(sizeof(int)*vertexCount1 + 1);
    for(int j = 0; j < vertexCount1; j++){
        traced[j] = 0;
    }
    for(int j = 0; j < vertexCount1; j++){
        for(int k = 0; k < vertexCount1; k++){
            if(head -> destination == traced[k]){
                flagk++;
            }
        }
        for(int l = 0; l < vertexCount1; l++){
            if(head -> destination == traced[l]){
                flagl++;
            }
        }
        if(flagk == 0 && flagl != 0){
            traced[j] = head -> destination;
            totalCost += head -> weight;
            head = head -> next;
        }else if(flagk != 0 && flagl == 0){
            traced[j] = head -> source;
            totalCost += head -> weight;
            head = head -> next;
        }else if(flagk == 0 && flagl == 0){
            traced[j] = head -> destination;
            traced[j+1] == head -> source;
            totalCost += head -> weight;
            j++;
            head = head -> next;
        }
    }
    traced[vertexCount1] = totalCost;
    return traced;
}

EDGE* insertEdge(EDGE* head, int destination1, int weight1, int source1, EDGE* prev){
    if(weight1 < head -> weight){
        EDGE* newvertex = (EDGE*)malloc(sizeof(EDGE));
        newvertex -> weight = weight1;
        newvertex -> destination = destination1;
        newvertex -> source = source1;
        if(prev != NULL){
            prev -> next = newvertex;
        }
        newvertex -> next = head;
        return newvertex;
    }else{
        insertEdge(head->next, destination1, weight1, source1, head);
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
    int* MST = (int*)malloc(sizeof(int)*vertexCount);

    for(i = 0; i < edgeCount; i++){
        edgeHead = init(edgeHead);
    }

    MST = kruskalMST(edgeHead, vertexCount);

    for(int j = 0; j < vertexCount; j++){
        printf("Traced Vertex: %d\n", MST[j]);
    }
    printf("Total Cost of MST: %d\n", MST[vertexCount]);
    
    printf("Please enter the Destination of vertex to be added: ");
    scanf("%d", &insertDestination);
    printf("Please enter the Source of vertex to be added: ");
    scanf("%d", &insertSource); 
    printf("Please enter the Weight of vertex to be added: ");
    scanf("%d", &insertWeight);

    edgeHead = insertEdge(edgeHead, insertDestination, insertWeight, insertSource, edgePrev);

    for(int j = 0; j < vertexCount; j++){
        printf("NEW Traced Vertex: %d\n", MST[j]);
    }
    printf("NEW Total Cost of MST: %d\n", MST[vertexCount]);

}

