#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_STRING_SIZE 100
#define MAX_FILENAME_SIZE 100

struct binaryTree{
	char* val;
	struct binaryTree* right, *left;
};


typedef struct binaryTree TREE;

TREE* insert(TREE* root,char* val) {
	if(root == NULL) {
		TREE* newnode = (TREE*)malloc(sizeof(TREE));
		newnode->val = (char*)malloc(sizeof(char)*MAX_STRING_SIZE);
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}
	if(strcmp(val, root -> val) < 0) {
		root->left = insert(root->left,val);
	}else if(strcmp(val, root -> val) > 0) {
		root->right = insert(root->right,val);
	}
	return root;
}



void delete(TREE* NODE){
    TREE* temp;
    if(NODE -> right == NULL && NODE -> left == NULL){
        free(NODE);
    }else if(NODE -> right == NULL && NODE -> left != NULL){
        NODE -> val = (NODE -> left) -> val;
        free(NODE -> left);
    }else if(NODE -> right != NULL && NODE -> left == NULL){
        NODE -> val = (NODE -> right) -> val;
        free(NODE -> right);
    }else if(NODE -> right != NULL && NODE -> left != NULL){

    }
}

void printInorder(TREE* root, int* inOrderList2){
	if(root == NULL) {
		return;
	}
	else{
		printInorder(root->left, inOrderList2);
		printf("%s\n",root->val);
		printInorder(root->right, inOrderList2);
	}
}


int main(int argc, char** argv) {

	FILE* ptr;
	TREE* root = NULL;
	char* temp;
    int* inOrderList = (int*)malloc(sizeof(int) * 1);
	int itr = 0;

	ptr = fopen("odev.txt", "a+");
	if(ptr == NULL){
		printf("File cannot be opened\n");
	}


	temp = malloc(sizeof(char)*MAX_STRING_SIZE);
	
	for(int i = 0; i < 5; i++){
		do{
			temp[itr] = fgetc(ptr);
			itr++;
		}while(temp[itr - 1] != ' ');
		root = insert(root, temp);
	}
	
	printInorder(root, inOrderList);


	return 0;
}