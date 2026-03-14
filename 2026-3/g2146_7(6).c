#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}Point;

int arr[101][101];
int graph[101][101];
int visit[101][101];
int N;
int idx = 1;
Point sum[101][10001];
int idx2[100001];
int min = 100000000;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void bfs(Point p){
	Point queue[10001];
	int front=0,rear=0;
	queue[front++] = p;
	graph[p.x][p.y] = idx;
	idx2[idx] = 0;
	sum[idx][idx2[idx]++] = p;
	while(front>rear){
		Point now = queue[rear++];
		for(int i=0;i<4;i++){
			int nx=now.x+dx[i],ny=now.y+dy[i];
			if((nx < N && nx > -1)&&(ny < N && ny > -1)){
				if(arr[nx][ny] == 1 && visit[nx][ny] == 0){
					queue[front].x = nx;
					queue[front++].y = ny;
					visit[nx][ny] = idx;
					graph[nx][ny] = idx;
					sum[idx][idx2[idx]].x = nx;
					sum[idx][idx2[idx]++].y = ny;
				}
			}
		}
	}
}

void bfs2(int aa){
	Point queue[10001];
	int front = 0, rear = 0;
	for(int i=0;i<idx2[aa];i++){
		queue[front++] = sum[aa][i];
	}
	int count = 0;

	int localvisit[101][101];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			localvisit[i][j] = visit[i][j];
		}
	}
	while(front>rear){
		count++;
		if(count>min) return;
		int now_front = front;
		while(now_front>rear){
			Point now = queue[rear++];
			for(int i=0;i<4;i++){
				int nx = now.x+dx[i], ny = now.y+dy[i];
				if((nx < N && nx > -1)&&(ny < N && ny > -1)){
					if(graph[nx][ny] != aa && graph[nx][ny] != 0){
						if(min > count) min = count;
						return;
					}
					if(localvisit[nx][ny] != aa){
						queue[front].x = nx;
						queue[front++].y = ny;
						localvisit[nx][ny] = aa;
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&arr[i][j]);
			graph[i][j] = 0;
			visit[i][j] = 0;
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(arr[i][j] == 1 && visit[i][j] == 0){
				visit[i][j] = 1;
				Point p = {i,j};
				bfs(p);
				idx++;
			}
		}
	}
	for(int i=1;i<idx;i++){
		bfs2(i);
	}
	printf("%d",min-1);
}
