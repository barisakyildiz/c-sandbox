void printInorder(TREE* root, LIST* HEAD, int counter){

    LIST* current = NULL;

	if(root == NULL) {
		return;
	}
	else{
		printInorder(root->left, HEAD, counter);
        if(counter == 0){
            current = (LIST*)malloc(sizeof(LIST));
            current -> next = NULL;
            current -> val = root -> val;
            HEAD -> next = current;
            counter++;
        }else{
            current = (LIST*)malloc(sizeof(LIST));
            HEAD -> next = current;
            current -> val = root -> val;
            counter++;
        }
		printf("%d\n",root->val);
		printInorder(root->right, current, counter);
	}
}