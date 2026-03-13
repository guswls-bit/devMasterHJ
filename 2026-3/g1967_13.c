#include <stdio.h>
#include <stdlib.h>

struct Node{
	int dest;
	int weight;
	struct Node* next;
};
typedef struct Node Node;

int n;
Node** graph;
int* visit;

int max_dist;
int far_node;

void addEdge(int u,int v,int w){
	Node* new = (Node*)malloc(sizeof(Node));
	new->dest = u;
	new->weight = w;
	new->next = graph[v];
	graph[v] = new;
}

void dfs(int now,int cur_dist){
	visit[now] = 1;
	if(cur_dist > max_dist){
		max_dist = cur_dist;
		far_node = now;
	}
	Node* cur = graph[now];;
	while(cur != NULL){
		if(visit[cur->dest] == 0){
			dfs(cur->dest, cur_dist + cur->weight);
		}
		cur = cur->next;
	}
}

int main(){
	scanf("%d",&n);
	graph = (Node**)malloc(sizeof(Node*)*(n+1));
	visit = (int*)calloc(n+1,sizeof(int));
	for(int i=0;i<n-1;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}

	dfs(1,0);
	max_dist = 0;
	for(int i=1;i<n+1;i++) visit[i] = 0;
	dfs(far_node,0);
	printf("%d",max_dist);
}
