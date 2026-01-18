#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
typedef struct Node Node;

void postOrder(Node* root){
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d\n",root->data);
}

Node* insert(Node* root, int data){
	if (root == NULL){
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	if(data < root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;

}

int main(){
	Node* root = NULL;
	int num;

	while(scanf("%d",&num) != EOF){
		root = insert(root,num);
	}

	postOrder(root);
	return 0;
}
