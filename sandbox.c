#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int val;
    struct node* next;

};

typedef struct node NODE;


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
    
    NODE* stackHead, *stackEnd;
    stackinit(stackHead, stackEnd);
    int i = 0;

    while(1){
        pushStack(stackHead, 5);
        i++;
    }
    
    return 0;
}