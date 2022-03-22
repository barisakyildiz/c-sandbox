#include <stdio.h>

//Function pointers are like normal pointers but they hace the capabiltiy to point to a function

int add(int a, int b){
    return a+b;
}

//Fonksiyon adları aynı zamanda pointer oldukları için & kullanmaya gerek yoktur

int main(){

    int result;
    int (*ptr)(int, int) = &add; //default prototype
    result = ptr(10,20);
    printf("%d", result);
    return 0;
}