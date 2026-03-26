#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
int A[9];
int order[8];
int visit[8];
int max = -10000;

int calc(){
	int sum = 0;
	for(int i=0;i<N-1;i++){
		sum += abs(order[i] - order[i+1]);
	}
	return sum;
}

void solve(int count){
	if(count == N){
		int cur = calc();
		if(cur > max){
			max = cur;
		}
		return;
	}
	for(int i=0;i<N;i++){
		if(!visit[i]){
			visit[i] = 1;
			order[count] = A[i];
			solve(count+1);
			visit[i] = 0;
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&A[i]);
	solve(0);

	printf("%d",max);
}
