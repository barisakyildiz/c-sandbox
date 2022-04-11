#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct{
    int top, capacity;
    char *array;
}stack;

stack *createStack(int);
char convertToBinary(int);
int countTotalBit(int);
int isFull(stack*);
int isEmpty(stack*);
void pushStack(stack* , char);
int popStack(stack*);

int main(){
    
    stack *stackTmp = createStack(100);
    int input, totalBits, digit;
    char digitChar;
    printf("Please enter the number that is going to converted: ");
    scanf("%d", &input);

    totalBits = countTotalBit(input);
    int totalbitsdivided = totalBits / 8;
    if(totalBits == 8 || totalbitsdivided == 0){
        totalBits = 8;
    }else if(totalBits == 16 || totalbitsdivided == 1){
        totalBits = 16;
    }else if(totalBits == 24 || totalbitsdivided == 2){
        totalBits = 24;
    }else if(totalBits == 32 || totalbitsdivided == 3){
        totalBits = 32;
    } 

    for(int i = 0; i < totalBits; i++){
        input, digit = convertToBinary(input);
        pushStack(stackTmp, digitChar);
    }


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
    char digitChar[1]; 
    digit = input % 2;
    printf("%d ", digit);    
    input = input / 2;
    sprintf(digitChar, "%d", digit);       
    return input, digit;
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

int countTotalBit(int n){
	int count=0, i;
	if(n==0) return 0;
	for(i=0; i < 32; i++){	
		if( (1 << i) & n)
			count=i;
	}
	return ++count;
}