#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int row;
	int col;
}Point;

int N, M;
char** graph;
int** visit;
int count=0;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(Point now){
	for(int i=0;i<4;i++){
		int nrow = now.row+dx[i], ncol = now.col+dy[i];
		if((nrow>-1 && nrow<N)&&(ncol>-1 && ncol<M)){
			if(graph[nrow][ncol] != 'X' && visit[nrow][ncol] == 0){
				Point next = {nrow,ncol};
				visit[nrow][ncol] = 1;
				if(graph[nrow][ncol] == 'P') count++;
				dfs(next);
			}
		}
	}
}

int main(){
	Point start;
	scanf("%d %d",&N,&M);
	graph = (char**)malloc(sizeof(char*)*N);
	visit = (int**)malloc(sizeof(int*)*N);
	for(int i=0;i<N;i++){
		graph[i] = (char*)malloc(sizeof(char)*(M+1));
		visit[i] = (int*)calloc(M,sizeof(int));
		scanf("%s",graph[i]);
		for(int j=0;j<M;j++){
			if(graph[i][j] == 'I'){
				start.row = i;
				start.col = j;
				visit[i][j] = 1;
			}
		}
	}
	dfs(start);
	if(count==0) printf("TT");
	else printf("%d",count);
}
