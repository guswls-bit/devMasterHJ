#include <stdio.h>

int N;
int roma[4] = {1,5,10,50};
int visited[1001];
int count = 0;

void back(int depth, int idx, int sum){
	if(depth == N){
		if(!visited[sum]){
			visited[sum] = 1;
			count++;
		}
		return;
	}

	for(int i=idx;i<4;i++){
		back(depth+1,i,sum+roma[i]);
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<1001;i++){
		visited[i] = 0;
	}
	back(0,0,0);
	printf("%d",count);
}
