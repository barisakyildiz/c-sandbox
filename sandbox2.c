#include<stdio.h>
#include<stdlib.h>

struct binaryTree{
	int val;
	struct binaryTree* right, *left;
};


typedef struct binaryTree TREE;

TREE* insert(TREE* root,int val) {


	if(root == NULL) {
		TREE* newnode = (TREE*)malloc(sizeof(TREE));
		newnode->val = val;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}
	if(val < root->val) {
		root->left = insert(root->left,val);
	}
	else{
		if(val > root->val) {
			root->right = insert(root->right,val);
		}
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

int printInorder(TREE* root, int counter, int* inOrderList2){
	if(root == NULL) {
		return -1;
	}
	else{
        counter++;
        counter++;
        counter++;
		printInorder(root->left, counter, inOrderList2);
        counter++;
        counter++;
        counter++;
		printf("%d\n",root->val);
		printInorder(root->right, counter, inOrderList2);
        counter++;
        counter++;
        counter++;
	}
    return counter;
}


int main(int argc, char** argv) {

	TREE* root = NULL;
    int counter = 0;
    int* inOrderList = (int*)malloc(sizeof(int) * 1);

	root = insert(root,100);
	root = insert(root,60);
	root = insert(root,110);
	root = insert(root,20);
	root = insert(root,10);
	root = insert(root,25);
	root = insert(root,120);
    root = insert(root,120);
	root = insert(root,110);
	root = insert(root,140);
	root = insert(root,-5);
	counter = printInorder(root, counter, inOrderList);
    printf("COUNTER %d\n", counter);


	return 0;
}

