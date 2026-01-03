#include <stdio.h>
#include <stdlib.h>

void dfs(int depth, int x, int y);

int** arr;
int r,c;
int visit[26];
int max=0;

int main(){
	char* str;
	scanf("%d %d", &r, &c);
	arr = (int**)malloc(sizeof(int*)*r);
	str = (char*)malloc(sizeof(char)*(c+1));
	for(int i=0;i<r;i++){
		arr[i] = (int*)malloc(sizeof(int)*c);
		scanf(" %s",str);
		for(int j=0;j<c;j++){
			arr[i][j] = str[j]-'A';
		}
	}
	for(int i=0;i<26;i++){
		visit[i] = 0;
	}
	visit[arr[0][0]] = 1;
	dfs(1,0,0);
	printf("%d",max);
	return 0;
}

void dfs(int depth, int x, int y){
	if(depth>max) max = depth;
	if(x-1>=0){
		if(!visit[arr[x-1][y]]){
			visit[arr[x-1][y]] = 1;
			dfs(depth+1,x-1,y);
			visit[arr[x-1][y]] = 0;
		}
	}
	if(x+1!=r){
		if(!visit[arr[x+1][y]]){
			visit[arr[x+1][y]] = 1;
			dfs(depth+1,x+1,y);
			visit[arr[x+1][y]] = 0;
		}
	}
	if(y-1>=0){
                if(!visit[arr[x][y-1]]){
                        visit[arr[x][y-1]] = 1;
                        dfs(depth+1,x,y-1);
                        visit[arr[x][y-1]] = 0;
                }
        }
        if(y+1!=c){
                if(!visit[arr[x][y+1]]){
                        visit[arr[x][y+1]] = 1;
                        dfs(depth+1,x,y+1);
                        visit[arr[x][y+1]] = 0;
                }
        }
}
