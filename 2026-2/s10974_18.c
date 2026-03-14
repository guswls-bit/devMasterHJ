#include <stdio.h>
#include <stdlib.h>

int N;
int* visit;
int* result;

void dfs(int idx){
	if(idx == N){
		for(int i=0;i<N;i++){
			printf("%d ",result[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=N;i++){
		if(visit[i] == 0){
			visit[i] = 1;
			result[idx] = i;
			dfs(idx+1);
			visit[i] = 0;
		}
	}
}

int main(){
	scanf("%d",&N);
	visit = (int*)calloc(N+1,sizeof(int));
	result = (int*)malloc(sizeof(int)*N);
	dfs(0);
}
