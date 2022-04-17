#include <stdio.h>
#include <stdlib.h>

typedef struct{
    
    int val;
    int *next;

}NODE;


void stackinit(NODE *head, NODE *end){
    head -> next = end;
    head -> val = 0;
}

void pushStack(NODE *head, int n){
    NODE *current = (NODE*) malloc (sizeof(NODE));
    current -> val = n;
    current -> next = head -> next;
    head -> next = current;
}

int popStack(NODE *head){
    int pop;
    NODE *current = (NODE*) malloc(sizeof(NODE));
    current = head -> next;
    head -> next = current -> next;
    pop = current -> val;
    free(current);
    return pop;
}

int main(){

    NODE *head, *end;

    stackinit(head, end);
    for(int i = 0; i< 25; i++){
        pushStack(head, i);
    }

    while(head -> next != end){
        printf("Popped from stack: %d \n", popStack(head));
    }

    return 0;
}