#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int left;
	int right;
}Node;

Node** graph;
int N;
int count = 0;
int last=0;
int finish = 0;


void addNode(int a,int b,int c){
	Node* node = (Node*)malloc(sizeof(Node));
	node->left = b;
	node->right = c;
	graph[a] = node;
}

void inorder(int cur){
	if(graph[cur]->left != -1){
		inorder(graph[cur]->left);
		count++;
		if(finish == 0) count++;
	}
	if(graph[cur]->right != -1){
		inorder(graph[cur]->right);
		count++;
		if(finish == 0) count++;
	}
	
	if(cur == last) finish = 1;
}
int main(){
	scanf("%d",&N);
	graph = (Node**)malloc(sizeof(Node*)*(N+1));
	for(int i=0;i<N;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addNode(a,b,c);
	}
	last = 1;
	while(graph[last]->right != -1){
		last = graph[last]->right;
	}	
	inorder(1);
	printf("%d",count);
}
