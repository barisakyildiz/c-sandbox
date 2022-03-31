#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int data;
    int *left;
    int *right;
}tree;

tree *createTree(int data){
    tree *T = malloc(sizeof(tree));
    T -> data = data;
    T -> left = NULL;
    T -> right = NULL;
    return T;
}

void pretraverse(tree *t){
    if (t == NULL) return;
    //visit(t);
    pretraverse(t -> left);
    pretraverse(t -> right);
}

tree *insert(tree *node, int data){
    if(node == NULL){
        return createTree(data);
    }
    if(data < node -> data){
        node -> left = insert(node -> left, data);
    }else if(data > node -> data){
        node -> right = insert(node -> right, data);
    }
    return node;
}

int main(){

    tree *tree1;

    tree1 = createTree(5);
    
    return 0;
}