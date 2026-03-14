#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
	int z;
}Node;

char*** arr;
int*** dist;
int L,R,C;

Node queue[500000];
int front,rear;

int dz[6] = {-1, 1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1,-1, 0, 0}; 
int dy[6] = {0, 0, 0, 0, 1,-1}; 

void bfs(Node start){
	front = 0, rear = 0;
	queue[front++] = start;
	dist[start.z][start.x][start.y] = 0;
	while(front != rear){
		Node cur = queue[rear++];
		if(arr[cur.z][cur.x][cur.y] == 'E'){
			printf("Escaped in %d minute(s).\n",dist[cur.z][cur.x][cur.y]);
			return;
		}

		for(int i=0;i<6;i++){
			int nz = cur.z + dz[i];
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if(nz < L && nx < R && ny < C){
				if(nz >= 0 && nx >= 0 && ny >= 0){
					if(arr[nz][nx][ny] != '#' && dist[nz][nx][ny] == -1){
						dist[nz][nx][ny] = dist[cur.z][cur.x][cur.y] + 1;
						queue[front].z = nz;
						queue[front].y = ny;
						queue[front++].x = nx;
					}
				}
			}
		}
	}
	printf("Trapped!\n");
}

int main(){
	while(1){
		scanf("%d %d %d",&L,&R,&C);
		if((L==0)&&(R==0&&C==0)) break;
		arr = (char***)malloc(sizeof(char**)*L);
		dist = (int***)malloc(sizeof(int**)*L);
		Node start;
		for(int i=0;i<L;i++){
			arr[i] = (char**)malloc(sizeof(char*)*R);
			dist[i] = (int**)malloc(sizeof(int*)*R);
			for(int j=0;j<R;j++){
				arr[i][j] = (char*)malloc(sizeof(char)*C);
				dist[i][j] = (int*)malloc(sizeof(int)*C);
				for(int k=0;k<C;k++){
					scanf(" %c",&arr[i][j][k]);
					dist[i][j][k] = -1;
					if(arr[i][j][k] == 'S') {start.z = i;start.x = j;start.y = k;}
				}
			}
		}
		bfs(start);
		for(int i=0;i<L;i++){
			for(int j=0;j<R;j++){
				free(arr[i][j]);
				free(dist[i][j]);
			}
			free(arr[i]);
			free(dist[i]);
		}
		free(arr);
		free(dist);
	}
	return 0;
}
