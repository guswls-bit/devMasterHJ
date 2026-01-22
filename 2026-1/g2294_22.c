#include <stdio.h>
#include <stdlib.h>
#define INF 200000000

int N,K;
int* arr;
int* dp;

int main(){
	scanf("%d %d",&N,&K);
	arr = (int*)malloc(sizeof(int)*N);
	dp = (int*)malloc(sizeof(int)*K+1);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	dp[0] = 0;
	for(int i=1;i<K+1;i++){
		dp[i] = INF;
		for(int j=0;j<N;j++){
			if(i-arr[j] >= 0){
				if(dp[i-arr[j]] != INF){
					dp[i] = (dp[i]>dp[i - arr[j]] + 1)?(dp[i-arr[j]]+1):dp[i];
				}
			}
		}
	}
	printf("%d",(dp[K]!=INF)?dp[K]:-1);
	return 0;
}
