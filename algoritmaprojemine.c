#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
    for (i = size-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

void arrangeColors(int row, int** board, int N) {
    int i, j, k, colors[N];
    for(i = 0; i < N; i++){colors[i] = board[row][i];}
  // base case: if we have reached the last row, we are done
    if (row == N){
        printf("LMAO1");
      // print the final arrangement of the colors on the game board
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
      // exit the program
        exit(0);
    }

  // try all possible arrangements of colors for the current row
    for (i = 0; i < N; i++){
        // copy the colors array to the current row of the game board
        for (j = 0; j < N; j++){
            board[row][j] = colors[j];
            printf("LMAO2");
      }

      // check if the current arrangement is valid (i.e., each column contains exactly one instance of each color)
      int valid = 1;
      for (j = 0; j < N; j++){
        for (k = 0; k < N; k++){
            if (board[k][j] != colors[j]){
                printf("LMAO3");
                valid = 0;
                break;
            }
        }
        if (!valid){
            break;
        }
      }

    // if the current arrangement is valid, move to the next row
    if (valid){
      arrangeColors(row+1, board, N);
    }

    // if the current arrangement is not valid, shift the colors in the current row to the right by one position and try again
    shiftRight(colors, N);
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
    arrangeColors(0, arrayst -> arr, arrayst -> size);
    printf("\n\n\n");
    printMatrix(arrayst -> arr, arrayst -> size);
    getch();

    return 0;
}

