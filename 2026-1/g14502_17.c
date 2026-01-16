#include <stdio.h>
#include <stdlib.h>

int N,M;
int** graph;
int** visit;
int** temp;
int min = -1;

typedef struct{
	int x;
	int y;
}Point;

void bfs(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			temp[i][j] = graph[i][j];
		}
	}

	Point queue[65];
	int rear = 0, front = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(graph[i][j] == 2){
				queue[front].x = i;
				queue[front++].y = j;
			}
		}
	}
	
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};

	while(front != rear){
		int cx = queue[rear].x;
		int cy = queue[rear++].y;
		
		for(int i=0;i<4;i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if(nx >= 0 && nx < N && ny >= 0 && ny < M){
				if(temp[nx][ny] == 0){
					temp[nx][ny] = 2;
					queue[front].x = nx;
					queue[front++].y = ny;
				}
			}
		}
	}

	int count = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(!temp[i][j]) count++;
		}
	}
	if(count>min) min = count;
}


int main(){
	scanf("%d %d",&N,&M);
	graph = (int**)malloc(sizeof(int*)*N);
	visit = (int**)malloc(sizeof(int*)*N);
	temp = (int**)malloc(sizeof(int*)*N);
	for(int i=0;i<N;i++){
		graph[i] = (int*)malloc(sizeof(int)*M);
		visit[i] = (int*)malloc(sizeof(int)*M);
		temp[i] = (int*)malloc(sizeof(int)*M);
		for(int j=0;j<M;j++){
			scanf("%d",&graph[i][j]);
			visit[i][j] = graph[i][j];
		}
	}
	for(int i=0;i<N*M;i++){
		if(visit[i/M][i%M]) continue;
		for(int j=i+1;j<N*M;j++){
			if(visit[j/M][j%M]) continue;
			for(int k=j+1;k<N*M;k++){
				if(visit[k/M][k%M]) continue;
				graph[i/M][i%M] = 1;
				graph[j/M][j%M] = 1;
				graph[k/M][k%M] = 1;
				bfs();
				graph[i/M][i%M] = 0;
                                graph[j/M][j%M] = 0;
                                graph[k/M][k%M] = 0;
			}
		}
	}
	printf("%d",min);
	return 0;
}
