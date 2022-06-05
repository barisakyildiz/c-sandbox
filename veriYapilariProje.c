#include <stdio.h>
#include <stdlib.h>

const char shortMaze[] = "maze.txt"; //please enter the name of the text file that contains the maze

struct graphNode{
    int vertex;
    struct graphNode* next;
};

struct graph{
    int nVertex;
    struct graphNode** adjlist;
};

struct stackNode{
    int row;
    int column;
    struct stackNode* next;
};

struct rowColumn{
    int rowss;
    int columnss;
};

typedef struct rowColumn ROWCOLUMN;
typedef struct stackNode STACKNODE;
typedef struct graphNode GRAPHNODE;
typedef struct graph GRAPH;

ROWCOLUMN* getStartPoint(int** mazeMatrix, int rows, int cols){
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

ROWCOLUMN* getExitPoint(int** mazeMatrix, int rows, int cols){
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

/*GRAPHNODE* createGraphNode(int vertex){
    GRAPHNODE* newNode = (GRAPHNODE*)malloc(sizeof(GRAPHNODE));
    newNode -> vertex = vertex;
    newNode -> next = NULL;
    return newNode;
}

GRAPH* createGraph(int nVertices){
    int i;
    GRAPH* _graph = (GRAPH*)malloc(sizeof(GRAPH));
    _graph -> nVertex = nVertices;
    _graph -> adjlist = (GRAPHNODE**)malloc(nVertices * sizeof(GRAPHNODE*));
    for(i = 0; i < nVertices; i++){
        _graph -> adjlist[i] = NULL;
    }
    return _graph;
}*/

int isValid(int** isVisited, int rows, int cols, int selectedRow, int selectedColumn){
    //True ise 1 False ise 0 döndürür
    if(isVisited[selectedRow][selectedColumn] == 1){
        return 0;
    }else{
        if((selectedColumn != 0 || selectedColumn != (cols -1)) && (selectedRow != 0 || selectedRow != (rows - 1))){
            return 1;
        }
    }
}

int** allocateMaze(int rows, int cols){
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
        }else if(ch == ' '){
            mazeMatrix[row][offset - 1] = 1;
        }else if(ch == 'b'){
            mazeMatrix[row][offset - 1] = 2;
        }else if(ch == 'c'){
            mazeMatrix[row][offset - 1] = 3;
        }else if(ch == 'O'){
            mazeMatrix[row][offset - 1] = 4;
        }
    }
    fclose(ptr);
    return mazeMatrix;
}

/*void addGraphEdge(GRAPH* _graph, int source, int destination){
    GRAPHNODE* newNode = createGraphNode(destination);
    newNode -> next = _graph -> adjlist[source];
    _graph -> adjlist[source] = newNode;
    newNode = createGraphNode(source);
    newNode -> next = _graph -> adjlist[destination];
    _graph -> adjlist[destination] = newNode;
}*/

int isStackEmpty(STACKNODE *head, STACKNODE *end){
    if(head -> next == end){
        return 1;
    }else{
        return 0;
    }
}

void stackinit(STACKNODE *head, STACKNODE *end){
    head -> next = end;
    head -> row = 0;
    head -> column = 0;
}

void pushStack(STACKNODE *head, int row, int column){
    STACKNODE *current = (STACKNODE*) malloc (sizeof(STACKNODE));
    current -> column = column;
    current -> row = row;
    current -> next = head -> next;
    head -> next = current;
}

ROWCOLUMN* popStack(STACKNODE *head){
    ROWCOLUMN* pop = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    STACKNODE *current = (STACKNODE*)malloc(sizeof(STACKNODE));
    current = head -> next;
    head -> next = current -> next;
    pop -> columnss = current -> column;
    pop -> rowss = current -> row;
    free(current);
    return pop;
}

ROWCOLUMN* readFromFile(FILE* ptr){
    char ch;
    int rows = 0, columns = 0;
    ROWCOLUMN* returnStruct = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    if (NULL == ptr) {
        printf("Dosya Acilamadi \n");
    }
    printf("Dosyanin Icerigi\n");
    while (!feof(ptr)) {
        ch = fgetc(ptr);
        if(ch == '\n'){
            rows++;
        }else if(ch != '\n'){
            columns++;
        }
        printf("%c", ch);
    }
    columns = (columns- 1) / rows;
    returnStruct -> columnss = columns;
    returnStruct -> rowss = rows;
    return returnStruct;
}

int main(){
    
    ROWCOLUMN* returnStructMain = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    ROWCOLUMN* returnStartMain = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    ROWCOLUMN* returnExitMain = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    STACKNODE *stackHead = (STACKNODE*)malloc(sizeof(STACKNODE)), *stackEnd = (STACKNODE*)malloc(sizeof(STACKNODE));
    FILE* fp = fopen(shortMaze, "r+");
    returnStructMain = readFromFile(fp);
    printf("columns = %d\n", returnStructMain -> columnss);
    printf("rows = %d\n", returnStructMain -> rowss);
    fclose(fp);
    int **maze = allocateMaze(returnStructMain -> rowss ,returnStructMain -> columnss);
    int **isVisited;
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
        printf("\n");
        for(int j = 0; j < returnStructMain -> columnss; j++){
            printf("%d ", maze[i][j]);
        }
    }
    
    
    returnStartMain = getStartPoint(maze, returnStructMain -> rowss, returnStructMain -> columnss);
    printf("\n\nStart [%d] [%d]", returnStartMain -> rowss, returnStartMain -> columnss);
    returnExitMain = getExitPoint(maze, returnStructMain -> rowss, returnStructMain -> columnss);
    printf("\nExit [%d] [%d] \n", returnExitMain -> rowss, returnExitMain -> columnss);
    
    stackinit(stackHead, stackEnd);
    ROWCOLUMN* returnPopStack = (ROWCOLUMN*)malloc(sizeof(ROWCOLUMN));
    isVisited[(returnStartMain -> rowss)][returnStartMain -> columnss] = 1;
    
    do{
        if((maze[(returnStartMain -> rowss) - 1][returnStartMain -> columnss] != 0) && isValid(isVisited, returnStructMain -> rowss, returnStructMain -> columnss, (returnStartMain -> rowss) - 1, returnStartMain -> columnss)){
            pushStack(stackHead, returnStartMain -> rowss, returnStartMain -> columnss);
            isVisited[(returnStartMain -> rowss) - 1][returnStartMain -> columnss] = 1;
            returnStartMain -> rowss = (returnStartMain -> rowss) - 1;
            printf("Going to: %d", returnStartMain -> rowss - 1);
        }else if((maze[(returnStartMain -> rowss) + 1][returnStartMain -> columnss] != 0) && isValid(isVisited, returnStructMain -> rowss, returnStructMain -> columnss, (returnStartMain -> rowss) + 1, returnStartMain -> columnss)){
            pushStack(stackHead, returnStartMain -> rowss, returnStartMain -> columnss);
            isVisited[(returnStartMain -> rowss) + 1][returnStartMain -> columnss] = 1;
            returnStartMain -> rowss = (returnStartMain -> rowss) + 1;
            printf("Going to: %d", returnStartMain -> rowss + 1);
        }else if((maze[returnStartMain -> rowss][(returnStartMain -> columnss) + 1] != 0) && isValid(isVisited, returnStructMain -> rowss, returnStructMain -> columnss, returnStartMain -> rowss, (returnStartMain -> columnss) + 1)){
            pushStack(stackHead, returnStartMain -> rowss, returnStartMain -> columnss);
            isVisited[returnStartMain -> rowss][(returnStartMain -> columnss) + 1] = 1;
            returnStartMain -> columnss = (returnStartMain -> columnss) + 1;
            printf("Going to: %d", returnStartMain -> columnss + 1);
        }else if((maze[returnStartMain -> rowss][(returnStartMain -> columnss) - 1] != 0) && isValid(isVisited, returnStructMain -> rowss, returnStructMain -> columnss, returnStartMain -> rowss, (returnStartMain -> columnss)) - 1){
            pushStack(stackHead, returnStartMain -> rowss, returnStartMain -> columnss);
            isVisited[returnStartMain -> rowss][(returnStartMain -> columnss) - 1] = 1;
            returnStartMain -> columnss = (returnStartMain -> columnss) - 1;
            printf("Going to: %d", returnStartMain -> columnss - 1);
        }else{
            returnPopStack = popStack(stackHead);
            returnStartMain -> rowss = returnPopStack -> rowss;
            returnStartMain -> columnss = returnPopStack -> rowss;
        }
    }while((!isStackEmpty(stackHead, stackEnd)) && (returnStartMain -> rowss != returnExitMain -> columnss && returnStartMain -> columnss != returnExitMain -> columnss));


    return 0;
}