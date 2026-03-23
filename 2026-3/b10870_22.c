#include <stdio.h>

int N;
int memo[21];

int fibo(int a){
	if(memo[a] != -1){
		return memo[a];
	}
	return fibo(a-1) + fibo(a-2);
}

int main(){
	scanf("%d",&N);
	memo[0] = 0;
	memo[1] = 1;
	for(int i=2;i<21;i++){
		memo[i] = -1;
	}
	printf("%d",fibo(N));
}
