#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree;
typedef struct node{
    int data;
    tree left;
    tree right;
}node;

tree createTree(int data){
    tree T = (tree)malloc(sizeof(struct node));
    T -> data = data;
    T -> left = NULL;
    T -> right = NULL;
    return T;
}

void pretraverse(tree t){
    if (t==NULL) return;
    visit(t);
    pretraverse(t -> left);
    pretraverse(t -> right);
}



int main(){

    tree tree1;

    tree1 = createTree(5);
    
    return 0;
}