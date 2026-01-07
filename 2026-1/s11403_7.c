#include <stdio.h>
#include <stdlib.h>

void search(int a);

int** graph;
int N;

int main(){
	scanf("%d",&N);
	graph = (int**)malloc(sizeof(int*)*N);
	for(int i=0;i<N;i++){
		graph[i] = (int*)malloc(sizeof(int)*N);
		for(int j=0;j<N;j++){
			scanf(" %d",&graph[i][j]);
		}
	}
	for(int i=0;i<N;i++){
		search(i);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) printf("%d ",graph[i][j]);
		printf("\n");
	}
	for(int i=0;i<N;i++) free(graph[i]);
	free(graph);
	return 0;
}

void search(int a){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			graph[i][j] = graph[i][j] || (graph[i][a] && graph[a][j]);
		}
	}

}
