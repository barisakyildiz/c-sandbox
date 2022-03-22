#include <stdio.h>

typedef struct{
    int lenght;
    int width;
} rectangle;

typedef struct{
    int x;
    int y;
} position;

typedef struct{

    char owner[30];
    rectangle rectangle;
    position position;
} building;

int main(){
    building myBuilding = {"Baris Akyildiz", {5, 10}, {2, 3}};
    printf("Length is equal to %d, and width is: %d\n", myBuilding.rectangle[0], myBuilding.rectangle[1]);
    return 0;
}