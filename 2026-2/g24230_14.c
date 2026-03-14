#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int dest;
	struct Node* next;
};
typedef struct Node Node;

Node** graph;

int N;
int* C;
int* visited;
long long int count = 0;


void add(int u, int v){
	Node* node = (Node*)malloc(sizeof(Node));
	node->dest = v;
	node->next = graph[u];
	graph[u] = node;
}

void dfs(int curr, int p_col){
	visited[curr] = 1;
	if(C[curr] != p_col){
		count++;
	}

	Node* temp = graph[curr];
	while(temp != NULL){
		if(!visited[temp->dest]){
			dfs(temp->dest, C[curr]);
		}
		temp = temp->next;
	}
}

int main(){
	scanf("%d",&N);
	C = (int*)malloc(sizeof(int)*(N+1));
	graph = (Node**)calloc(N+1,sizeof(Node*));
	visited = (int*)calloc(N+1,sizeof(int));
	for(int i=1;i<=N;i++){
		scanf("%d",&C[i]);
	}
	int a,b;
	for(int i=0;i<N-1;i++){
		scanf("%d %d",&a,&b);
		add(a,b);
		add(b,a);
	}

	dfs(1,0);
	printf("%lld",count);

}
