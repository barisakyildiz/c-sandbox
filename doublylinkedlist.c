#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val;
    int *next;
    int *prev;
}NODE;

void push(NODE** head, int val){
    NODE *newnode = (NODE*) malloc(sizeof(NODE));
    newnode -> val = val;
    if(*head == NULL){
        newnode -> next = NULL;
        newnode -> prev = NULL;
        (*head) = newnode;
    }else{
        newnode -> next = (*head);
        newnode -> prev = NULL;
        (*head) -> prev = newnode;
        (*head) = newnode; //newnode
    }
}

void insert(NODE *head, int val){
    NODE *current = head;
    NODE *newnode = (NODE*) malloc(sizeof(NODE));
    newnode -> val = val;
    while(current -> next != NULL){
        current = current -> next;
    }
    newnode -> next = NULL;
    newnode -> prev = current;
    current -> next = newnode;
}

void del(NODE *head, int position){
    NODE *current = head;
    if(head == NULL){
        exit(0);
    }
    else{
        while(current -> next != NULL && position != 0){
            current = current -> next;
            position--;
        }
        NODE *temp1, *temp2;
        temp1 = current -> next;
        temp2 = current -> prev;
        if(current -> next == NULL){
            temp2 -> next = NULL;
            free(current);
        }else{
            temp2 -> next = current -> next;
            temp1 -> prev = current -> prev;
            free(current);
        }
    }
}

void printlist(NODE **head){
    NODE *temporary = *head;
    while(temporary != NULL){
        printf("%d - ", temporary -> val);
        temporary = temporary -> next;
    }
    printf("\n");
}

int main(){

    NODE **head = (NODE*) malloc(sizeof(NODE));
    

    push(head, 5);
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);

    printlist(head);

    return 0;
}