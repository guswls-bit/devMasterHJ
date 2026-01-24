#include <stdio.h>
#include <stdlib.h>

int n,T;
int* arr;
int* visit;
int* finished;
int cnt;

void dfs(int idx){
	visit[idx] = 1;
	int next = arr[idx];

	if(!visit[next]){
		dfs(next);
	}
	else if(!finished[next]){
		for(int i=next;i!=idx;i=arr[i]){
			cnt++;
		}
		cnt++;
	}
	finished[idx] = 1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);

		arr = (int*)malloc(sizeof(int)*(n+1));
		visit = (int*)calloc(n+1,sizeof(int));
		finished = (int*)calloc(n+1,sizeof(int));

		cnt = 0;

		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}

		for(int i=1;i<=n;i++){
			if(!visit[i])
				dfs(i);
		}

		printf("%d\n",n-cnt);
		free(arr);
		free(visit);
		free(finished);
	}
	return 0;
}
