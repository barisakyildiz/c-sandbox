#include <stdio.h>
#include <stdlib.h>
const int ARRAY_LENGTH = 15; 

void printarray(int *myarray, int length){
    for(int i= 0; i< length; i++){
        printf("%d, ", myarray[i]);
    }
    printf("\n");
}

int main(){

    int *p = malloc(sizeof(int) * ARRAY_LENGTH);

    for(int i= 0; i<ARRAY_LENGTH; i++){
        p[i] = i;
    } 

    printarray(p,ARRAY_LENGTH);

    p = realloc(p, sizeof(int) * 20);

    for(int i= 0; i<20; i++){
        p[i] = i;
    } 

    printarray(p,20);

    free(p);

    return 0;
}