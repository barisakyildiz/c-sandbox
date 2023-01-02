#include <stdio.h>
#include <stdlib.h>

struct color{
    int deger;
    struct color* next;
};

typedef struct color COLOR;

void printMatrix(int** matrix){
    for(int i = 0; i < sizeof(matrix) / 4 + 1; i++){
        for(int j = 0; j < sizeof(matrix) / 4 + !; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** getMatrix(){
    int n, i, j;
    printf("Please Enter the n of the matrix: ");
    scanf("%d", &n);
    int** A = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++){
        A[i] = (int*)malloc(sizeof(int) * n);
    }
    printf("White --> 1\nRed --> 2\nGreen --> 3\nBlue --> 4\nPurple --> 5\nPink --> 6\nBlack --> 7\nBrown --> 8\n\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Please enter the color to the %dx%d element of the matrix: ");
            scanf("%d", &A[i][j]);
        }
    }
    return A;
}

int main(){

    int** A;

    A = getMatrix();
    printMatrix(A);

    return 0;
}