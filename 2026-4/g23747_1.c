#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}Point;

char graph[1000][1001];
int R,C;
char cmd[200005];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(Point start){
	if(graph[start.x][start.y] == '.') return;
	Point queue[1000001];
	int rear=0,front=0;
	queue[rear++] = start;
	char nc = graph[start.x][start.y];
	graph[start.x][start.y] = '.';
	while(rear>front){
		Point cur = queue[front++];
		for(int i=0;i<4;i++){
			int nx = cur.x+dx[i],ny = cur.y+dy[i];
			if((nx < R && nx >= 0)&&(ny < C && ny >= 0)){
				if(graph[nx][ny] == nc){
					queue[rear].x = nx;
					queue[rear++].y = ny;
					graph[nx][ny] = '.';
				}
			}
		}
	}
}

void move(Point start){
	for(int i=0;cmd[i] != '\0';i++){
		if(cmd[i] == 'W'){
			bfs(start);
		}
		else if(cmd[i] == 'U'){
			start.x -= 1;
		}
		else if(cmd[i] == 'D'){
			start.x += 1;
		}
		else if(cmd[i] == 'L'){
			start.y -= 1;
		}
		else if(cmd[i] == 'R'){
			start.y += 1;
		}
	}
	graph[start.x][start.y] = '.';
	for(int i=0;i<4;i++){
		int nx = start.x+dx[i],ny = start.y+dy[i];
		if((nx < R && nx >= 0)&&(ny < C && ny >= 0)){
			graph[nx][ny] = '.';
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(graph[i][j] != '.'){
				printf("#");
			}	
			else printf(".");
		}
		printf("\n");
	}
}

int main(){
	scanf("%d %d",&R,&C);
	for(int i=0;i<R;i++){
		scanf("%s",graph[i]);
	}
	Point h;
	scanf("%d%d",&h.x,&h.y);
	scanf("%s",cmd);
	h.x--;
	h.y--;
	move(h);
}
