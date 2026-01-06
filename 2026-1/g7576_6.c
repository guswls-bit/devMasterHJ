#include <stdio.h>
#include <stdlib.h>
void bfs();

typedef struct{
    int x;		
    int y;		
}Point;	

int** arr;
int** visit;
Point* queue;
int front = 0,rear = 0;
int M,N;

int main(){
	scanf("%d %d",&M,&N);
	arr = (int**)malloc(sizeof(int*)*N);
	visit = (int**)malloc(sizeof(int*)*N);
	queue = (Point*)malloc(sizeof(Point)*M*N);
	for(int i=0;i<N;i++){
		arr[i] = (int*)malloc(sizeof(int)*M);
		visit[i] = (int*)malloc(sizeof(int)*M);
		for(int j=0;j<M;j++){
			scanf(" %d",&arr[i][j]);
			visit[i][j] = 0;
			if(arr[i][j]==1){
				queue[front].x = i;
				queue[front++].y = j;
				visit[i][j] = 1;
			}
			if(arr[i][j] == -1) visit[i][j] = 1;
		}
	}
	bfs();
	return 0;
}

void bfs(){
	int init;
	Point now;
	int depth=0;
	while(rear!=front){
		init=front;
		while(rear!=init){
			now.x = queue[rear].x;
			now.y = queue[rear++].y;
			if(now.x-1>=0){
				if(visit[now.x-1][now.y]==0){
					queue[front].x = now.x-1;
					queue[front++].y = now.y;
					visit[now.x-1][now.y] = 1;
				} 
			}	
			if(now.x+1!=N){
				if(visit[now.x+1][now.y] == 0){
					queue[front].x = now.x+1;
					queue[front++].y = now.y;
					visit[now.x+1][now.y] = 1;
				}
			}
			if(now.y-1>=0){
					if(visit[now.x][now.y-1]==0){
							queue[front].x = now.x;
							queue[front++].y = now.y-1;
							visit[now.x][now.y-1] = 1;
					}
			}
			if(now.y+1!=M){
					if(visit[now.x][now.y+1] == 0){
							queue[front].x = now.x;
							queue[front++].y = now.y+1;
							visit[now.x][now.y+1] = 1;
					}
			}
		}
		depth++;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(visit[i][j] == 0){
				printf("-1");
				return;
			}
		}
	}
	printf("%d",depth-1);
	return;
}
