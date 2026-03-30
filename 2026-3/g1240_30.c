#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int dest;
	int weight;
	struct Node* next;
};
typedef struct Node Node;
Node** graph;
int* visit;

int N,M;
int min = 10000000;

void addEdge(int u,int v, int w){
	Node* node = (Node*)malloc(sizeof(Node));
	node->dest = u;
	node->weight = w;
	node->next = graph[v];
	graph[v] = node;
}

void dfs(int u,int v,int weight){
	visit[u] = 1;
	if(u==v) min = (weight < min)?weight:min;
	Node* cur = graph[u];
	while(cur != NULL){
		if(visit[cur->dest] == 0){
			dfs(cur->dest,v,weight+cur->weight);
		}
		cur = cur->next;
	}
}

int main(){
	scanf("%d%d",&N,&M);
	graph = (Node**)malloc(sizeof(Node*)*(N+1));
	visit = (int*)calloc(N+1,sizeof(int));

	for(int i=0;i<N-1;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		dfs(a,b,0);
		printf("%d\n",min);
		for(int i=0;i<N;i++){
			visit[i+1] = 0;
		}
		min = 100000000;
	}
}
