#include <stdio.h>
#include <stdlib.h>

void degistir(int* ad){
    ad[4] = 11;
}

int main(){
    
    int* a = (int*)malloc(sizeof(int) * 5);
    
    for(int i = 0; i < 5; i++){
        a[i] = i;
    }
    for(int i = 0; i < 5; i++){
        printf("5. eleman %d\n", a[4]);
    }
    
    degistir(a);
    
    for(int i = 0; i < 5; i++){
        printf("5. eleman %d\n", a[4]);
    }
    
    return 0;
}