#include <stdio.h>
#include <stdlib.h>

void bfs();

int N,M;
int** arr;
int** visit;

int main(){
	scanf("%d %d",&N,&M);
	arr = (int**)malloc(sizeof(int*)*N);
	visit = (int**)malloc(sizeof(int*)*N);
	char a[1001];
	for(int i=0;i<N;i++){
		visit[i] = (int*)malloc(sizeof(int)*M);
		arr[i] = (int*)malloc(sizeof(int)*M);
		scanf(" %s",a);
		for(int j=0;j<M;j++){
			arr[i][j] = a[j]-'0';
			visit[i][j] = 0;
		}
	}
	bfs();
	return 0;
}

void bfs(){
	int queue[10001][2];
	int rear=0, front=0;
	int depth=1;
	visit[0][0] = 1;
	if(arr[0][1]){
		queue[front][0] = 0;
		queue[front][1] = 1;
		visit[0][1] = 1;
		front++;
	}
	if(arr[1][0]){
		queue[front][0] = 1;
		queue[front][1] = 0;
		visit[1][0] = 1;
		front++;
	}
	int x,y,point;
	while(1){
		point = front;
		while(rear!= point){
		x = queue[rear][0];
		y = queue[rear][1];
		rear++;
		if(x==N-1&&y==M-1) break;
		
		if(x+1<N) {
			if(arr[x+1][y]&&visit[x+1][y]==0){
				queue[front][0] = x+1;
				queue[front][1] = y;
				visit[x+1][y] = 1;
				front++;
			}	
		}
		if(y+1<M){
			if(arr[x][y+1]&&visit[x][y+1]==0){
				queue[front][0] = x;
				queue[front][1] = y+1;
				visit[x][y+1] = 1;
				front++;
			}

		}
		if(x-1>=0){
			if(arr[x-1][y] && visit[x-1][y]==0){
				queue[front][0] = x-1;
				queue[front][1] = y;
				visit[x-1][y] = 1;
				front++; 
			}
		}
		if(y-1>=0){
			if(arr[x][y-1] && visit[x][y-1]==0){
				queue[front][0] = x;
				queue[front][1] = y-1;
				visit[x][y-1] = 1;
				front++; 
			}
		}
		}
		if(x==N-1&&y==M-1) break;
		depth++;
	}
	printf("%d",depth+1);
	return;
}
