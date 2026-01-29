#include <stdio.h>
#include <stdlib.h>

int N;
int* arr;
int* visit;
int* result;
int res_count = 0;

int dfs(int s, int c){
	if(visit[c]){
		if(s == c){
			return 1;
		}
		return 0;
	}

	visit[c] = 1;
	return dfs(s,arr[c]);
}

int main(){
	scanf("%d",&N);
	arr = (int*)malloc(sizeof(int)*N);
	visit = (int*)malloc(sizeof(int)*N);
	result = (int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		arr[i] -= 1;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){visit[j] = 0;}
		if(dfs(i,i)){
			result[res_count++] = i;
		}
	}
	printf("%d\n",res_count);
	for(int i=0;i<res_count;i++){
		printf("%d\n",result[i]+1);
	}
	return 0;
}
