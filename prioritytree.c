#include <stdio.h> 

int tree_arraysize = 20;
int heap_size = 0;
const int INF = 10000;

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int get_right_child(int A[], int index){
    if((((2*index) +1) < tree_arraysize) && (index >= 1)){
        return(2*index) + 1;
    }else{
        return -1;
    }
}

int get_left_child(int A[], int index){
    if(((2*index) < tree_arraysize) && (index >= 1)){
        return(2*index);
    }else{
        return -1;
    }
}

int get_parent(int A[], int index){
    if((index >1) && (index < tree_arraysize)){
        return index / 2;
    }else{
        return -1;
    }
}

int main(){



    return 0;
}