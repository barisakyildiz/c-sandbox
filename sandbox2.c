#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sex4321(int arryy[]){
    printf("Sex : %d", arryy[1]);
    arryy[2] = 31;
    return 1;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    sex4321(arr);
    printf("\n%d", arr[2]);
    return 0;
}