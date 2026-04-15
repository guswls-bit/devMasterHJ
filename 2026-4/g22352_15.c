#include <stdio.h>
#include <stdlib.h>

int before[31][31];
int after[31][31];
int visit[31][31];
int N,M;

typedef struct{
	int x;
	int y;
}Point;

int diff = 0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


void solve(Point a,int target){
	Point queue[1000];
	int rear=0, front =0;
	queue[rear++] = a;
	int origin = before[a.x][a.y];
	visit[a.x][a.y]  = 1;
	before[a.x][a.y] = target;
	while(front < rear){
		Point cur = queue[front++];
		for(int i=0;i<4;i++){
			int nx=cur.x+dx[i], ny=cur.y+dy[i];
			if((nx>=0&&nx<N)&&(ny>=0&&ny<M)){
				if(visit[nx][ny] == 0&&(before[nx][ny] == origin)){
					queue[rear].x = nx;
					queue[rear++].y = ny;
					visit[nx][ny] = 1;
					before[nx][ny] = target;
				}
			}
		}
	}
	
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&before[i][j]);
		}
	}
	for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        scanf("%d",&after[i][j]);
                	visit[i][j] = 0;
		}
        }
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(before[i][j] != after[i][j]){
				Point cur = {i,j};
				solve(cur,after[i][j]);
				diff = 1;
				break;
			}	
		}
		if(diff) break;
	}
	for(int i=0;i < N; i++) {
                for (int j = 0; j < M; j++) {
                        if (before[i][j] != after[i][j]) {
                                printf("NO");
                                return 0;
                        }
                }
        }
	
	printf("YES");
}
