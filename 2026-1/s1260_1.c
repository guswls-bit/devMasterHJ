#include <stdio.h>
#include <stdlib.h>
void dfs(int V);
void bfs(int depth,int V);

int* visit;
int** graph;
int N,M;
int queue[1001];
int front, rear;

int main(){
	int R,C,V;
	scanf("%d %d %d",&N, &M, &V);

	visit = (int*)malloc(sizeof(int)*N);
	graph = (int**)malloc(sizeof(int*)*N);
	for(int i=0;i<N;i++){
		graph[i] = (int*)malloc(sizeof(int)*N);
		visit[i] = 0;
		for(int j=0;j<N;j++)
			graph[i][j] = 0;
	}
	for(int i=0;i<M;i++){
		scanf("%d %d",&R,&C);
		graph[R-1][C-1] = 1;
		graph[C-1][R-1] = 1;
	}
	dfs(V-1);
	for(int i=0;i<N;i++) visit[i] = 0;
	printf("\n");
	bfs(0,V-1);
	return 0;
}

void dfs(int V){
	visit[V] = 1;
    	printf("%d ", V+1);
	for(int i=0;i<N;i++){
		if(graph[V][i]==1&&(visit[i]==0)){
			dfs(i);	
		}
	}
}

void bfs(int depth, int V){
	visit[V] = 1;
	printf("%d ",V+1);
	front = 0, rear = 0;
	for(int i=0;i<N;i++){
		if(graph[V][i]==1&&(visit[i]==0)){
			queue[front++] = i;
			printf("%d ",i+1);
			visit[i] = 1;
		}
	}
	while(rear!=front){
		V = queue[rear++];
		for(int i=0;i<N;i++){
			if(graph[V][i]==1&&(visit[i]==0)){
				queue[front++] = i;
				printf("%d ",i+1);
				visit[i] = 1;
			}
		}
	}
	
}
