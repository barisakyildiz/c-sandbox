#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int top, capacity;
    int *array;
}stack;

stack *createStack(int capacity){
    stack *stackTemp = malloc(sizeof(stack));
    stackTemp -> capacity = capacity;
    stackTemp -> top = -1;
    stackTemp -> array = (int*)malloc(sizeof(int) * (stackTemp -> capacity));
    return stackTemp;
}

int isFull(stack *stackTemp){
    return stackTemp -> top == (stackTemp -> capacity) - 1;
}

int isEmpty(stack *stackTemp){
    return stackTemp -> top == -1;
}

void pushStack(stack *stackTemp, int item){
    if(isFull(stackTemp)){
        printf("WARNING : Stack is FULL\n");
        return;
    }else{
        stackTemp -> array[++stackTemp -> top] = item;
        printf("%d pushed to the stack\n", item);
    }
}

int popStack(stack *stackTemp){
    if(isEmpty(stackTemp)){
        return INT_MIN;
    }else{
        return stackTemp -> array[stackTemp -> top];
    }
}


int main(){
    
    stack *stackTmp = createStack(100);

    pushStack(stackTmp, 10);
    pushStack(stackTmp, 20);
    pushStack(stackTmp, 30);

    int a = popStack(stackTmp);

    printf("%d popped from the stack \n", a);
    printf("capacity: %d \n", stackTmp -> capacity);


    return 0;
}