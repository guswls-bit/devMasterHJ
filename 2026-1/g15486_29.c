#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int T;
	int P;
}Node;
int N;
Node* arr;
int* dp;

int main(){
	scanf("%d",&N);
	arr = (Node*)malloc(sizeof(Node)*(N+2));
	dp = (int*)calloc(N+2,sizeof(int));
	for(int i=1;i<=N;i++){
		scanf("%d %d",&arr[i].T,&arr[i].P);
	}
	
	int max = 0;

	for(int i=1;i<=N+1;i++){
		max = (max > dp[i])?max:dp[i];
		if(i>N) break;
		int n = i + arr[i].T;

		if(n <= N+1){
			dp[n] = (dp[n]>max+arr[i].P)?dp[n]:max+arr[i].P;
		}
	}
	printf("%d",max);
	return 0;
}
