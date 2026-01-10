#include <stdio.h>
#include <stdlib.h>
void bfs();

typedef struct{
    int x;		
    int y;
    int z;		
}Point;	

int*** arr;
int*** visit;
Point* queue;
int front = 0,rear = 0;
int M,N,H;

int main(){
	scanf("%d %d %d",&M,&N,&H);
	arr = (int***)malloc(sizeof(int**)*H);
	visit = (int***)malloc(sizeof(int**)*H);
	queue = (Point*)malloc(sizeof(Point)*M*N*H);
	for(int i=0;i<H;i++){
		arr[i] = (int**)malloc(sizeof(int*)*N);
		visit[i] = (int**)malloc(sizeof(int*)*N);
		for(int j=0;j<N;j++){
			arr[i][j] = (int*)malloc(sizeof(int)*M);
			visit[i][j] = (int*)malloc(sizeof(int)*M);
			for(int k=0;k<M;k++){
				scanf(" %d",&arr[i][j][k]);
				visit[i][j][k] = 0;
				if(arr[i][j][k]==1){
					queue[front].z = i;
					queue[front].x = j;
					queue[front++].y = k;
					visit[i][j][k] = 1;
				}
				if(arr[i][j][k] == -1) visit[i][j][k] = 1;
			}
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
			now.z = queue[rear].z;
			now.x = queue[rear].x;
			now.y = queue[rear++].y;
			if(now.x-1>=0){
				if(visit[now.z][now.x-1][now.y]==0){
					queue[front].z = now.z;
					queue[front].x = now.x-1;
					queue[front++].y = now.y;
					visit[now.z][now.x-1][now.y] = 1;
				} 
			}	
			if(now.x+1!=N){
				if(visit[now.z][now.x+1][now.y] == 0){
					queue[front].z = now.z;
					queue[front].x = now.x+1;
					queue[front++].y = now.y;
					visit[now.z][now.x+1][now.y] = 1;
				}
			}
			if(now.y-1>=0){
				if(visit[now.z][now.x][now.y-1]==0){
					queue[front].z = now.z;
					queue[front].x = now.x;
					queue[front++].y = now.y-1;
					visit[now.z][now.x][now.y-1] = 1;
				}
			}
			if(now.y+1!=M){
				if(visit[now.z][now.x][now.y+1] == 0){
					queue[front].z = now.z;
					queue[front].x = now.x;
					queue[front++].y = now.y+1;
					visit[now.z][now.x][now.y+1] = 1;
				}
			}
			if(now.z+1!=H){
				if(visit[now.z+1][now.x][now.y] == 0){
					queue[front].z = now.z+1;
					queue[front].x = now.x;
					queue[front++].y = now.y;
					visit[now.z+1][now.x][now.y] = 1;
				}
			}
			if(now.z-1>=0){
				if(visit[now.z-1][now.x][now.y] == 0){
					queue[front].z = now.z-1;
					queue[front].x = now.x;
					queue[front++].y = now.y;
					visit[now.z-1][now.x][now.y] = 1;
				}
			}
		}
		depth++;
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				if(visit[i][j][k] == 0){
					printf("-1");
					return;
				}
			}
		}
	}
	printf("%d",depth-1);
	return;
}

