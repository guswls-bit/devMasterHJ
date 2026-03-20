#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char left;
	char right;
}Node;
int N;
Node* graph;

void preorder(char a){
	printf("%c",a);
	if(graph['A'-a].left != '.'){
		preorder(graph['A'-a].left);
	}
	if(graph['A'-a].right != '.'){
                preorder(graph['A'-a].right);
        }
}

void inorder(char a){
        if(graph['A'-a].left != '.'){
                inorder(graph['A'-a].left);
        }
	printf("%c",a);
        if(graph['A'-a].right != '.'){
                inorder(graph['A'-a].right);
        }
}

void postorder(char a){
        if(graph['A'-a].left != '.'){
                postorder(graph['A'-a].left);
        }
        if(graph['A'-a].right != '.'){
                postorder(graph['A'-a].right);
        }
	printf("%c",a);
}

int main(){
	scanf("%d",&N);
	graph = (Node*)malloc(sizeof(Node)*N);
	for(int i=0;i<N;i++){
		char a,b,c;
		scanf(" %c %c %c",&a,&b,&c);
		graph['A'-a].left = b;
		graph['A'-a].right = c;
	}
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
}
