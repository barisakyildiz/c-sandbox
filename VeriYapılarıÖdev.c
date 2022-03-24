#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int *bottom;
    int value; 
    int *next;
}NODE;

void printlist(NODE *head, int counter){
    NODE *temporary = head;
    printf("Linked List:\n");
    while(temporary != NULL){
        printf("%d ", temporary -> value);
        if(counter-1 != 0){
            printf("- ");
            counter--;
        }
        temporary = temporary -> next;
    }
    printf("\n");
}

int returnNodeNum(int n){
    int flag1 = 0;
    while(n > 2){
        n = (n/2)+1;
        flag1++;
    }
    return flag1;
}

NODE *create_new_node(int value){
    NODE *result = malloc(sizeof(NODE));
    result -> value = value;
    result -> next = NULL;
    return result;
}

NODE *insert_at_head(NODE *head, NODE *node_to_insert){
    node_to_insert -> next = head;
    return node_to_insert;
}

int main(){
    NODE *head = NULL;
    NODE *tmp;
    int n, nodeSet;

    printf("Please enter the number of 'NODES': \n");
    scanf("%d", &n);
    nodeSet = returnNodeNum(n) + 1;
    printf("nodeSet: %d\n", nodeSet);

    for(int i=n; i>0; i--){
        tmp = create_new_node(i);
        head = insert_at_head(head, tmp);
    }

    printlist(head, n);
    
    return 0;
}
