#include <stdio.h>
#include <stdlib.h>
int flood_fill(int x, int y);

int** arr;
int** visit;
int N;

int main(){
	int result[625];
	scanf("%d",&N);
	arr = (int**)malloc(sizeof(int*)*N);
	visit = (int**)malloc(sizeof(int*)*N);
	char* str = (char*)malloc(sizeof(char)*N);
	for(int i=0;i<N;i++){
		arr[i] = (int*)malloc(sizeof(int)*N);
		visit[i] = (int*)malloc(sizeof(int)*N);
		scanf(" %s",str);
		for(int j=0;j<N;j++){
			arr[i][j] = str[j]-'0';
			visit[i][j] = 0;
		}
	}
	int index = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(arr[i][j] && !visit[i][j]){
				result[index++] = flood_fill(i,j);
			}
		}
	}
	int temp;
	for(int i=0;i<index-1;i++){
		for(int j=0;j<index-i-1;j++){
			if(result[j]>result[j+1]){
				temp = result[j];
				result[j] = result[j+1];
				result[j+1] = temp;
			}
		}
	}
	printf("%d\n",index);
	for(int i=0;i<index;i++) printf("%d\n",result[i]);
	return 0;
}

int flood_fill(int x,int y){
	int count=0;
	int queue[626][2];
	int rear=0 ,front=0;
	queue[front][0] = x;
	queue[front++][1] = y;
	visit[x][y] = 1;
	int now[2];
	while(rear!= front){
		now[0] = queue[rear][0];
		now[1] = queue[rear++][1];
		count++;
		if(now[0]-1>=0){
                        if(arr[now[0]-1][now[1]] && !visit[now[0]-1][now[1]]){
                                queue[front][0] = now[0]-1;
                                queue[front++][1] = now[1];
                                visit[now[0]-1][now[1]]=1;
                        }
                }
                if(now[0]+1!=N){
                        if(arr[now[0]+1][now[1]] && !visit[now[0]+1][now[1]]){
                                queue[front][0] = now[0]+1;
                                queue[front++][1] = now[1];
                                visit[now[0]+1][now[1]] = 1;
                        }
		}
		if(now[1]-1>=0){
                        if(arr[now[0]][now[1]-1] && !visit[now[0]][now[1]-1]){
                                queue[front][0] = now[0];
                                queue[front++][1] = now[1]-1;
                                visit[now[0]][now[1]-1]=1;
                        }
                }
                if(now[1]+1!=N){
                        if(arr[now[0]][now[1]+1] && !visit[now[0]][now[1]+1]){
                                queue[front][0] = now[0];
                                queue[front++][1] = now[1]+1;
                                visit[now[0]][now[1]+1] = 1;
                        }
                }
		

	}
	
	return count;
}
