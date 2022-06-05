#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch() fonksiyonu için kütüphane
#include <unistd.h> //sleep() fonksiyonu Linux kütüphanesi
#include <windows.h> //sleep() fonksiyonu Windows kütüphanesi
#include <time.h>

const char shortMaze[] = "maze.txt"; //Lütfen Labirentin bulunduğu .txt dosyasının adını giriniz

struct stackNode{
    int row;
    int column;
    struct stackNode* next;
}; //stack üzerinde işlem yapılırken kullanılan stack node'ları

struct rowColumn{
    int rowss;
    int columnss;
}; //Matris indislerini fonksiyonlardan tek parça halinde döndürmek için kullanılan struct

typedef struct rowColumn ROWCOLUMN;
typedef struct stackNode STACKNODE;

ROWCOLUMN* getStartPoint(int** mazeMatrix, int rows, int cols){     //Labirentin Baslama noktasinin indislerini struct olarak döndüren fonksiyon
    ROWCOLUMN* startStruct = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    for(int i = 1; i < rows - 1; i++){
        for(int j = 1; j < cols - 1 ; j++){
            if(mazeMatrix[i][j] == 2){
                startStruct -> rowss = i;
                startStruct -> columnss = j;
                return startStruct;
            }
        }
    }
    return startStruct;
}

ROWCOLUMN* getExitPoint(int** mazeMatrix, int rows, int cols){      //Labirentin Bitis noktasinin indislerini struct olarak döndüren fonksiyon
    ROWCOLUMN* exitStruct = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    for(int i = 1; i < rows - 1; i++){
        for(int j = 1; j < cols - 1 ; j++){
            if(mazeMatrix[i][j] == 3){
                exitStruct -> rowss = i;
                exitStruct -> columnss = j;
                return exitStruct;
            }
        }
    }
    return exitStruct;
}

int isValid(int** isVisited, int **maze, int rows, int cols, int selectedRow, int selectedColumn){  //Bir sonraki gidilecek noktanın geçerli olup olmadığını boolean olarak döndüren fonksiyon
    if(isVisited[selectedRow][selectedColumn] == 1 || maze[selectedRow][selectedColumn] == 0){
        return 0;
    }else{
        return 1;
    }
}

int** allocateMaze(int rows, int cols, char** mazeChar){  //Labirent matrisini oluşturan fonksiyon (0 duvar, 1 bosluk, 2 baslangic, 3 cikis, 4 elma)
    FILE* ptr;
    char ch;
    int offset = 0, row = 0, **mazeMatrix;
    mazeMatrix = malloc(sizeof(int*) * rows);
    for(int i = 0; i < rows; i++){
        mazeMatrix[i] = malloc(sizeof(int*) * cols);
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            mazeMatrix[i][j] = 0;
        }
    }
    ptr = fopen(shortMaze, "r+");
    if(NULL == ptr){
        printf("Dosya Acilamadi\n");
    }
    while ((ch = fgetc(ptr)) != EOF){
        
        if(ch != '\n'){
            offset++;
        }else if(ch == '\n'){
            row++;
            offset = 0;
        }
        if(ch == '+' || ch == '-' || ch == '|'){
            mazeMatrix[row][offset - 1] = 0;
            mazeChar[row][offset - 1] = ch;
        }else if(ch == ' '){
            mazeMatrix[row][offset - 1] = 1;
            mazeChar[row][offset - 1] = ch;
        }else if(ch == 'b'){
            mazeMatrix[row][offset - 1] = 2;
            mazeChar[row][offset - 1] = ch;
        }else if(ch == 'c'){
            mazeMatrix[row][offset - 1] = 3;
            mazeChar[row][offset - 1] = ch;
        }else if(ch == 'O'){
            mazeMatrix[row][offset - 1] = 4;
            mazeChar[row][offset - 1] = ch;
        }
    }
    fclose(ptr);
    return mazeMatrix;
}

int isStackEmpty(STACKNODE *head, STACKNODE *end){ //Stack'in boş olup olmadığını kontrol eden fonksiyon
    if(head -> next == end){
        return 1;
    }else{
        return 0;
    }
}

void stackinit(STACKNODE *head, STACKNODE *end){  //Stack'i initialize eden fonksiyon
    head -> next = end;
    head -> row = 0;
    head -> column = 0;
}

void pushStack(STACKNODE *head, int row, int column){ //Stack'in push fonksiyonu
    STACKNODE *current = (STACKNODE*) malloc (sizeof(STACKNODE));
    current -> column = column;
    current -> row = row;
    current -> next = head -> next;
    head -> next = current;
}

ROWCOLUMN* popStack(STACKNODE *head){  //Stack'in pop fonksiyonu (indisleri yine struct yapisinda donduruyor)
    ROWCOLUMN* pop = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    STACKNODE *current = (STACKNODE*)malloc(sizeof(STACKNODE));
    current = head -> next;
    head -> next = current -> next;
    pop -> columnss = current -> column;
    pop -> rowss = current -> row;
    free(current);
    return pop;
}

ROWCOLUMN* readFromFile(FILE* ptr){  //Dosyadan okumaya yarayan fonksiyon
    char ch;
    int rows = 0, columns = 0;
    ROWCOLUMN* returnStruct = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    if (NULL == ptr) {
        printf("Dosya Acilamadi \n");
    }
    while (!feof(ptr)) {
        ch = fgetc(ptr);
        if(ch == '\n'){
            rows++;
        }else if(ch != '\n'){
            columns++;
        }
    }
    columns = (columns- 1) / rows;
    returnStruct -> columnss = columns;
    returnStruct -> rowss = rows;
    return returnStruct;
}

ROWCOLUMN* checkAppleValid(int** maze, int rows, int cols){ //Elmanın yerleştireleceği hücre yerleştirmeye uygun mu diye kontrol eder
    ROWCOLUMN* apple = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    int randRow = rand()%rows, randCol = rand()%cols;
    if(maze[randRow][randCol] == 0){
        free(apple);
        checkAppleValid(maze, rows, cols);
    }else{
        apple -> rowss = randRow;
        apple -> columnss = randCol;
        return apple;
    }
}

void putApples(char** mazeChar, int** maze, int rows, int cols){ //rastgele bir biçimde labirente belirli sayıda elma ekler
    srand(time(NULL));
    ROWCOLUMN* apples;
    int randomRow;
    int randomColumn;
    int numOfApples = 15;
    for(int i = 0; i < numOfApples; i++){
        apples = checkAppleValid(maze, rows, cols);
        randomRow = apples -> rowss;
        randomColumn = apples -> columnss;
        if(maze[randomRow][randomColumn] == 4){
            i--;
        }
        mazeChar[randomRow][randomColumn] = 'O';
        maze[randomRow][randomColumn] = 4;
    }
}

void returnWhenFound(int **maze, char** mazeChar, int **visited, int selectedRow, int selectedColumn, int rows, int cols, STACKNODE* head, STACKNODE* end, int endRow, int endColumn){
    system("cls");                                                               //Oyunu başlatan ve sürdüren asıl fonksiyon, çözüldüğü anda returnler
    ROWCOLUMN* returnPopStack = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    int points = 0, flag = 0;
    float delay = 100;
    while(!isStackEmpty(head, end)){
        if(selectedRow == endRow && selectedColumn == endColumn){
            printf("\n\nMAZE :");
            for(int i = 0; i < rows; i++){
                printf("\n");
                for(int j = 0; j < cols; j++){
                    printf("%c", mazeChar[i][j]);
                }
            }
            printf("\nLabirent Cozuldu\n");
            printf("Toplam Puan: %d\n", points);
            return;
        }
        if(isValid(visited, maze, rows, cols, selectedRow + 1, selectedColumn)){
            usleep(delay);
            system("cls");
            flag = 0;
            selectedRow++;
            visited[selectedRow][selectedColumn] = 1;
            pushStack(head, selectedRow, selectedColumn);
            if(maze[selectedRow][selectedColumn] == 4){
                points = points + 10;
            }
            mazeChar[selectedRow][selectedColumn] = '*';
            printf("\n\nMAZE :");
            for(int i = 0; i < rows; i++){
                printf("\n");
                for(int j = 0; j < cols; j++){
                    printf("%c", mazeChar[i][j]);
                }
            }
            printf("\nGidiliyor [%d][%d]\n", selectedRow, selectedColumn);
            printf("Mevcut Puan = %d\n", points);
        }else if(isValid(visited, maze, rows, cols, selectedRow - 1, selectedColumn)){
            usleep(delay);
            system("cls");
            flag = 0;
            selectedRow--;
            visited[selectedRow][selectedColumn] = 1;
            pushStack(head, selectedRow, selectedColumn);
            if(maze[selectedRow][selectedColumn] == 4){
                points = points + 10;
            }
            mazeChar[selectedRow][selectedColumn] = '*';
            printf("\n\nMAZE :");
            for(int i = 0; i < rows; i++){
                printf("\n");
                for(int j = 0; j < cols; j++){
                    printf("%c", mazeChar[i][j]);
                }
            }
            printf("\nGidiliyor [%d][%d]\n", selectedRow, selectedColumn);
            printf("Mevcut Puan = %d\n", points);
        }else if(isValid(visited, maze, rows, cols, selectedRow, selectedColumn + 1)){
            usleep(delay);
            system("cls");
            flag = 0;
            selectedColumn++;
            visited[selectedRow][selectedColumn] = 1;
            pushStack(head, selectedRow, selectedColumn);
            if(maze[selectedRow][selectedColumn] == 4){
                points = points + 10;
            }
            mazeChar[selectedRow][selectedColumn] = '*';
            printf("\n\nMAZE :");
            for(int i = 0; i < rows; i++){
                printf("\n");
                for(int j = 0; j < cols; j++){
                    printf("%c", mazeChar[i][j]);
                }
            }
            printf("\nGidiliyor [%d][%d]\n", selectedRow, selectedColumn);
            printf("Mevcut Puan = %d\n", points);
        }else if(isValid(visited, maze, rows, cols, selectedRow, selectedColumn - 1)){
            usleep(delay);
            system("cls");
            flag = 0;
            selectedColumn--;
            visited[selectedRow][selectedColumn] = 1;
            pushStack(head, selectedRow, selectedColumn);
            if(maze[selectedRow][selectedColumn] == 4){
                points = points + 10;
            }
            mazeChar[selectedRow][selectedColumn] = '*';
            printf("\n\nMAZE :");
            for(int i = 0; i < rows; i++){
                printf("\n");
                for(int j = 0; j < cols; j++){
                    printf("%c", mazeChar[i][j]);
                }
            }
            printf("\nGidiliyor [%d][%d]\n", selectedRow, selectedColumn);
            printf("Mevcut Puan = %d\n", points);
        }else{
            usleep(delay);
            system("cls");
            if(flag == 0){
                points = points - 5;
                flag = 1;
            }
            returnPopStack = popStack(head);
            mazeChar[selectedRow][selectedColumn] = ' ';
            selectedRow = returnPopStack -> rowss;
            selectedColumn = returnPopStack -> columnss;
            printf("\n\nMAZE :");
            for(int i = 0; i < rows; i++){
                printf("\n");
                for(int j = 0; j < cols; j++){
                    printf("%c", mazeChar[i][j]);
                }
            }
            printf("\nStack'ten POP'landi ve geri donuluyor : [%d] [%d]\n", selectedRow, selectedColumn);
            printf("Mevcut Puan = %d\n", points);
        }
    }
    printf("Stack Bosaldi\n");
}

int main(){
    
    ROWCOLUMN* returnStructMain = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    ROWCOLUMN* returnStartMain = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    ROWCOLUMN* returnExitMain = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    STACKNODE *stackHead = (STACKNODE*)malloc(sizeof(STACKNODE)), *stackEnd = (STACKNODE*)malloc(sizeof(STACKNODE));
    FILE* fp = fopen(shortMaze, "r+");
    returnStructMain = readFromFile(fp);
    fclose(fp);
    int **isVisited;
    char **mazeChar = malloc(sizeof(char*) * (returnStructMain -> rowss));
    int selectedRow, selectedColumn, endRow, endColumn;
    isVisited = malloc(sizeof(int*) * (returnStructMain -> rowss));
    
    for(int i = 0; i < returnStructMain -> rowss; i++){
        isVisited[i] = malloc(sizeof(int*) * (returnStructMain -> columnss));
    }
    
    for(int i = 0; i < returnStructMain -> rowss; i++){
        for(int j = 0; j < returnStructMain -> columnss; j++){
            isVisited[i][j] = 0;
        }
    }
    
    for(int i = 0; i < returnStructMain -> rowss; i++){
        mazeChar[i] = malloc(sizeof(char*) * (returnStructMain -> columnss));
    }
   
    int **maze = allocateMaze(returnStructMain -> rowss, returnStructMain -> columnss, mazeChar);
    
    printf("\n\nMAZE :");
    for(int i = 0; i < returnStructMain -> rowss; i++){
        printf("\n");
        for(int j = 0; j < returnStructMain -> columnss; j++){
            printf("%c", mazeChar[i][j]);
        }
    }
    
    returnStartMain = getStartPoint(maze, returnStructMain -> rowss, returnStructMain -> columnss);
    printf("\n\nStart [%d] [%d]", returnStartMain -> rowss, returnStartMain -> columnss);
    returnExitMain = getExitPoint(maze, returnStructMain -> rowss, returnStructMain -> columnss);
    printf("\nExit [%d] [%d] \n", returnExitMain -> rowss, returnExitMain -> columnss);
    
    stackinit(stackHead, stackEnd);
    isVisited[(returnStartMain -> rowss)][returnStartMain -> columnss] = 1;
    selectedRow = returnStartMain -> rowss;
    selectedColumn = returnStartMain -> columnss;
    endRow = returnExitMain -> rowss;
    endColumn = returnExitMain -> columnss;
    pushStack(stackHead, selectedRow, selectedColumn);
    printf("Cozmeye Baslamak Icin Enter tusuna basiniz, elmalar oyun basladiktan sonra yerlestirilecektir rastgele olarak yerlestirilecektir: \n");
    getch();
    putApples(mazeChar, maze, returnStructMain -> rowss, returnStructMain -> columnss);
    returnWhenFound(maze, mazeChar, isVisited, selectedRow, selectedColumn, returnStructMain -> rowss, returnStructMain -> columnss, stackHead, stackEnd, endRow, endColumn);
    printf("Cikis icin enter tusuna basiniz: \n");
    getch();

    return 0;
}