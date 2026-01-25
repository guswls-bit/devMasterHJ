#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a>b)?a:b)

int N;
int* arr;
int* dp;
int main(){
	scanf("%d",&N);
	arr = (int*)malloc(sizeof(int)*N);
	dp = (int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	dp[0] = arr[0];
	if(N>0) dp[1] = arr[0]+arr[1];
	int a,b,c,d;
	for(int i=2;i<N;i++){
		a = dp[i-1];
		b = dp[i-2] + arr[i];
		c = dp[i-3] + arr[i-1] + arr[i];
		dp[i] = MAX(a, MAX(b, c));
	}
	printf("%d",dp[N-1]);
	
}
