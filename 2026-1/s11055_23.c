#include <stdio.h>
#include <stdlib.h>

int N;
int* A;
int* dp;

int main(){
	scanf("%d",&N);
	A = (int*)malloc(sizeof(int)*N);
	dp = (int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		dp[i] = A[i];
	}	
	for(int i=1;i<N;i++){
		for(int j=0;j<i;j++){
			if(A[j] < A[i]){
				if(dp[i] < dp[j] + A[i]){
					dp[i] = dp[j] + A[i];
				}
			}
		}
	}
	int max=0;
	for(int i=0;i<N;i++){
		if(max<dp[i]){
			max = dp[i];
		}
	}
	printf("%d",max);
	return 0;
}
