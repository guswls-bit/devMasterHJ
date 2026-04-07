#include <stdio.h>
#include <stdlib.h>

int N;
char** graph;
int min=10000000, max=-11111;


void dfs(int x,int y,int val, char op){
	if(graph[x][y] >= '0' && graph[x][y] <= '5'){
		int num = graph[x][y] - '0';
		if(op == '+') val += num;
		else if(op == '-') val -= num;
		else val *= num;
	}	
	else{
		op = graph[x][y];
	}
	
	if(x==N-1 && y== N-1){
		if(val > max) max = val;
		if(val < min) min = val;
		return;
	}

	if(x  + 1 < N) dfs(x+1,y, val,op);
	if(y + 1 <N ) dfs(x,y+1,val,op);
}
int main(){
	scanf("%d",&N);
	graph = (char**)malloc(sizeof(char*)*N);
	
	for(int i=0;i<N;i++){
		graph[i] = (char*)malloc(sizeof(char)*(N+1));
		for(int j=0;j<N;j++){
			scanf(" %c",&graph[i][j]);
		}
	}
	dfs(0,0,0,'+');
	printf("%d %d",max,min);
}
