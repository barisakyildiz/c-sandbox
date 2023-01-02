#include <stdio.h>
#include <stdlib.h>

void swap(int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

int HoarePartition(int* arr, int pivotIndex){
    int startOfArr = arr[0];
    int i = 0, j = (sizeof(arr) / 4) + 1;
    while(i < j){
        while(arr[i] < pivotIndex){i++;}
        while(arr[j] > pivotIndex){j--;}
    }
    swap(arr[i], arr[j]);
    swap(arr[0], arr[j]);
    return j;
}

void quickSort(int* arr){
    if(0 < (sizeof(arr) / 4) - 1){
        int s = HoarePartition(arr, 0);
        quickSort(arr)
    }
}

int main(){



    return 0;
}