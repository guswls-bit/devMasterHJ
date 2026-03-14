#include <stdio.h>

#define INF 100000000

int main(){
	int N;
	scanf("%d",&N);
	int arr[1000];
	int dp[1000];
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		dp[i] = INF;
	}
	
	dp[0] = 0;
	for(int i=0;i<N;i++){
		if(dp[i] == INF) continue;

		for(int j=1;j<= arr[i];j++){
			if(i+j <N){
				if(dp[i+j] > dp[i] + 1){
					dp[i + j] = dp[i] + 1;
				}
			}
		}
	}
	if(dp[N-1] == INF)
		printf("-1");
	else
		printf("%d",dp[N-1]);
}
