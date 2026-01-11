#include <stdio.h>
#include <stdlib.h>

long long int N,X;
long long int* memo;
long long int* H;

long long int solve(long long int N, long long int X){
	if(N==0) return 1;
	if(X==1) return 0;
	else if(X <= 1+H[N-1]) return solve(N-1, X-1);
	else if(X == 1 + H[N-1] +1) return memo[N-1] + 1;
	else if(X<= H[N] - 1) return (memo[N-1] +1) + solve(N-1,X-(1+H[N-1]+1));
	else if(X==H[N]) return memo[N];
}


int main(){
	scanf("%lld %lld",&N,&X);
	memo = (long long int*)malloc(sizeof(long long int)*(N+2));
	memo[0] = 1;
	H = (long long int*)malloc(sizeof(long long int)*(N+2));
	H[0] = 1;
	for(int i=1;i<N+1;i++){
		memo[i] = memo[i-1] + 1 + memo[i-1];
		H[i] = 1 + H[i-1] + 1 + H[i-1] + 1;
	}
	printf("%lld",solve(N,X));
	return 0;
}
