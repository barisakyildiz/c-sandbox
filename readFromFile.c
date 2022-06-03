// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Driver code
int main()
{
    FILE* ptr;
    char ch;
    int rows = 0, columns = 0;
    ptr = fopen("maze.txt", "r+");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
 
    while (!feof(ptr)) {
        ch = fgetc(ptr);
        if(ch == '\n'){
            rows++;
        }else if(ch != '\n' || ch != '\0'){
            columns++;
        }
        printf("%c", ch);
    }
    fclose(ptr);
    printf("rows = %d\n", rows);
    columns = (columns- 1) / rows;
    printf("columns = %d\n", columns);
    return 0;
}