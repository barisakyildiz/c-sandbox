#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 6  // size of the game board
#define NUM_COLORS 6  // number of colors

// array to store the game board, where board[i][j] represents the color at row i and column j
char board[N][N];

// array to store the colors
char colors[NUM_COLORS] = {'R', 'B', 'G', 'P', 'Y', 'S'};

// function to shift the elements of an array to the right by one position
void shift_right(char *arr, int size) {
  char temp = arr[size-1];
  for (int i = size-1; i > 0; i--) {
    arr[i] = arr[i-1];
  }
  arr[0] = temp;
}

// recursive function to arrange the colors on the game board
void arrange_colors(int row) {
  // base case: if we have reached the last row, we are done
  if (row == N) {
    // print the final arrangement of the colors on the game board
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("%c ", board[i][j]);
      }
      printf("\n");
    }
    // exit the program
    exit(0);
  }

  // try all possible arrangements of colors for the current row
  for (int i = 0; i < NUM_COLORS; i++) {
    // copy the colors array to the current row of the game board
    for (int j = 0; j < N; j++) {
      board[row][j] = colors[j];
    }

    // check if the current arrangement is valid (i.e., each column contains exactly one instance of each color)
    int valid = 1;
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (board[k][j] != colors[j]) {
          valid = 0;
          break;
        }
      }
      if (!valid) {
        break;
      }
    }

    // if the current arrangement is valid, move to the next row
    if (valid) {
      arrange_colors(row+1);
    }

    // if the current arrangement is not valid, shift the colors in the current row to the right by one position and try again
    shift_right(colors, N);
  }
}

int main() {
  // start arranging the colors on the game board from the first row
  arrange_colors(0);
  return 0;
}