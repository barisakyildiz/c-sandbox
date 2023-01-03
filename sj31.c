#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct color{
    int deger;
    struct color* next;
};

struct arraySt{
    int size;
    int** arr;
};

typedef struct color COLOR;
typedef struct arraySt ARRAYST;

void printMatrix(int** matrix, int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void shiftRight(int* arr, int size){
    int temp = arr[size-1], i;
    for(i = size-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

int isValid(int row, int** board, int size, int col){
    int i, flag = 1;
    for(i = row; i >= 0; i--){
        if(board[row][col] == board[i][col] && row != i){
            flag = 0;
        }
    }
    return flag;
}

int swapColors(int row, int** board, int size, int backflag){
    int i, j, k, count = 1, isvalid, flag = 1;
    printf("SWAP DEBUG");
    if(count < size){
        if(row == size){
            return 1;
        }
        for(i = 0; i < size; i++){
            isvalid = isValid(row, board, size, i);
            if(isvalid == 0){
                flag = 0;
            }
        }
        if(flag == 1 && row + 1 < size){
            swapColors(row + 1, board, size, backflag);
        }else if(flag == 0){
            printf("FLAG DEBUG");
            for(i = 0; i < size - 1; i++){
                flag = 1;
                shiftRight(board[row], size);
                for(j = 0; j < size; j++){
                    isvalid = isValid(row, board, size, j);
                    if(isvalid == 0){
                        flag = 0;
                    }
                }
                if(flag == 1){
                    break;
                }
            }
            count++;
            flag = 1;
        }
    }else{
        return 1;
    }
}

ARRAYST* getMatrix(){
    ARRAYST* arrayst = (ARRAYST*)malloc(sizeof(ARRAYST));
    int n, i, j;
    printf("Please Enter the n of the matrix: ");
    scanf("%d", &n);
    if(n < 3 || n > 8){
        printf("Size of the Matrix cannot be smaller than 3 or bigger than 8");
        sleep(3);
        abort();
    }
    printf("White --> 1\nRed --> 2\nGreen --> 3\nBlue --> 4\nPurple --> 5\nPink --> 6\nBlack --> 7\nBrown --> 8\n\n");
    int** A = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < n; i++){
        A[i] = (int*)malloc(n * sizeof(int*));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Please enter the color to the %dx%d element of the matrix: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    arrayst -> arr = A;
    arrayst -> size = n;
    return arrayst;
}

int main(){
    
    ARRAYST* arrayst;
    arrayst = getMatrix();
    printMatrix(arrayst -> arr, arrayst -> size);
    printf("\n\n");
    sleep(3);
    swapColors(0, arrayst -> arr, arrayst -> size, 0);
    printf("\n\n\n");
    printMatrix(arrayst -> arr, arrayst -> size);
    sleep(5);

    return 0;
}

