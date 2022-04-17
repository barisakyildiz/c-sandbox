#include <stdio.h>

int main(){

    int a[100];
    int N = 50;
    int i, j;
    a[1] = 0; 

    for(i = 2; i <= N; i++){
        a[i] = 1;
    }

    for(i = 2; i<=N/2; i++){
        for(j = 2; j<=N/i; j++){
            a[i*j] = 0;
        }
    }

    for(i = 1; i <= N; i++){
        if(a[i]){
            printf("%d ", i);
        }
    }

    return 0;
}