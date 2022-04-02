#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int top, capacity;
    char *array;
}stack;

stack *createStack(int);
char convertToBinary(int);
int countBit(int);
int isFull(stack*);
int isEmpty(stack*);
void pushStack(stack* , char);
int popStack(stack*);

int main(){
    
    stack *stackTmp = createStack(100);
    int input;
    printf("Please enter the number that is going to converted: ");
    scanf("%d", &input);

    pushStack(stackTmp, 10);
    pushStack(stackTmp, 20);
    pushStack(stackTmp, 30);

    int a = popStack(stackTmp);

    printf("%c popped from the stack \n", a);
    printf("capacity: %d \n", stackTmp -> capacity);


    return 0;
}

stack *createStack(int capacity){
    stack *stackTemp = malloc(sizeof(stack));
    stackTemp -> capacity = capacity;
    stackTemp -> top = -1;
    stackTemp -> array = (char*)malloc(sizeof(char) * (stackTemp -> capacity));
    return stackTemp;
}

char convertToBinary(int input){
    int digit;
    char digitChar; 
    digit = input % 2;    
    input = input / 2;
    digitChar = digit + '0';        
    return digitChar, input;
}

int isFull(stack *stackTemp){
    return stackTemp -> top == (stackTemp -> capacity) - 1;
}

int isEmpty(stack *stackTemp){
    return stackTemp -> top == -1;
}

void pushStack(stack *stackTemp, char item){
    if(isFull(stackTemp)){
        printf("WARNING : Stack is FULL\n");
        return;
    }else{
        stackTemp -> array[++stackTemp -> top] = item;
        printf("%c pushed to the stack\n", item);
    }
}

int popStack(stack *stackTemp){
    if(isEmpty(stackTemp)){
        return INT_MIN;
    }else{
        return stackTemp -> array[stackTemp -> top];
    }
}

int countBit(int n){
	int count=0, i;
	if(n==0) return 0;
	for(i=0; i < 32; i++){	
		if( (1 << i) & n)
			count=i;
	}
	return ++count;
}