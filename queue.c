#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val;
    int *next;
}Q;

void enqueue(Q **q, int val){
    Q *new = (Q*)malloc(sizeof(Q));
    new -> val = val;
    if(*q == NULL){
        new -> next = NULL;
        *q = new;
    }else{
        new -> next = *q;
        *q = new;
    }
}

int dequeue(Q **q){
    int x;
    if(*q == NULL){
        printf("QUEUE IS EMPTY\n");
    }else{
        Q *current = *q;
        Q *before = current;
        while(current -> next != NULL){
            before = current;
            current = current -> next;
        }
        x = current -> val;
        before -> next = NULL;
        free(current);
        return x;
    }
}

int main(){

    Q *q = NULL;
    int x;

    enqueue(q, 5555);
    enqueue(q, 3333);
    enqueue(q, 2222);

    x = dequeue(q);
    printf("%d\n", x);
    x = dequeue(q);
    printf("%d\n", x);
    x = dequeue(q);
    printf("%d\n", x);

    return 0;
}