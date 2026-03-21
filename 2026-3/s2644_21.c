#include <stdio.h>
#include <stdlib.h>

int N;
int** graph;
int* visit;
int dest;

void dfs(int cur, int depth){
	if(visit[dest]) return;
	visit[cur] = 1;
	if(cur == dest){
		printf("%d",depth);
	}
	for(int i=1;i<=N;i++){
		if(visit[i] == 0 && graph[cur][i] == 1){
			dfs(i, depth+1);
		}
	}
}

int main(){
	scanf("%d",&N);
	graph = (int**)malloc(sizeof(int*)*(N+1));
	visit = (int*)calloc(N+1,sizeof(int));
	for(int i=0;i<=N;i++){
		graph[i] = (int*)calloc(N+1,sizeof(int));
	}
	int c;
	scanf("%d %d",&c,&dest);
	int lines;
	scanf("%d",&lines);
	for(int i=0;i<lines;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	dfs(c,0);
	if(visit[dest] == 0) printf("-1");
}
