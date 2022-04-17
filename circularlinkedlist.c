#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int val;
    int *next;

}NODE;


void allocate(NODE* head, int n){
    NODE* current = head;
    NODE* temp;
    current -> val = 1;
    current -> next = NULL;
    for(int i = 2; i < n; i++){
        if(current -> next != NULL){
            current = current -> next;
        }
        current -> next = (NODE*) malloc(sizeof(NODE));
        temp = current -> next;
        temp -> val = i;
        temp -> next = NULL;
    }

    temp -> next = (NODE*) malloc(sizeof(NODE)); //opsiyonel çözemedim
    temp -> next = head;
}

void printlist(NODE *head){
    NODE *temporary = head;
    while(temporary != NULL){
        printf("%d - ", temporary -> val);
        temporary = temporary -> next;
    }
    printf("\n");
}

int main(){

    NODE* head;
    int n = 15;

    allocate(head, n);
    printlist(head);


    return 0;
}