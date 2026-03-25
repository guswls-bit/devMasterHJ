#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
	int val;
}Point;

int N,K;
int** graph;
int** visit;
Point queue[50000];
int front=0,rear=0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int compare(const void *a, const void *b) {
    return ((Point *)a)->val - ((Point *)b)->val;
}	

void bfs(int S){
	int time = 0;
	while(front > rear){
		if(time == S) return;
		int now_front = front;
		time++;
		while(now_front > rear){
			Point cur = queue[rear++];
			for(int i=0;i<4;i++){
				int nx = cur.x+dx[i],ny = cur.y + dy[i];
				if((nx<N&&nx>-1)&&(ny<N&&ny>-1)){
					if(graph[nx][ny] == 0){
						graph[nx][ny] = cur.val;
						queue[front].x = nx;
						queue[front].y = ny;
						queue[front++].val = cur.val;
					}
				}
			}	
		}
	}
}


int main(){
	scanf("%d %d",&N,&K);
	graph = (int**)malloc(N*sizeof(int*));
	for(int i=0;i<N;i++){
		graph[i] = (int*)malloc(sizeof(int)*N);
		for(int j=0;j<N;j++){
			scanf("%d",&graph[i][j]);
			if(graph[i][j] != 0) {
				queue[front].x = i;
				queue[front].y = j;
				queue[front++].val = graph[i][j];
			}
		}
	}
	qsort(queue,front, sizeof(Point),compare);
	int S,X,Y;
	scanf("%d %d %d",&S,&X,&Y);
	bfs(S);
	printf("%d",graph[X-1][Y-1]);
}
