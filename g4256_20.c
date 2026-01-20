#include <stdio.h>
#include <stdlib.h>

int T,N;
int* graph[2];

void search(int idx, int start,int end){
	if(start >= end) return;
	int temp=-1;
	for(int i=start;i<end;i++){
		if(graph[0][idx] == graph[1][i]){
			temp = i;
			break;
		}
	}
	if(temp == -1) return;
	search(idx+1,start,temp);
	search(idx+1+(temp-start),temp+1,end);
	printf("%d ",graph[0][idx]);
}

int main(){
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&N);
		graph[0] = (int*)malloc(sizeof(int)*N);
		graph[1] = (int*)malloc(sizeof(int)*N);
		
		for(int j = 0;j<N;j++){
			scanf("%d",&graph[0][j]);	
		}
		for(int j=0;j<N;j++){
			scanf("%d",&graph[1][j]);
		}
		search(0,0,N);
		printf("\n");
		free(graph[0]);
		free(graph[1]);
	}
	return 0;
}
