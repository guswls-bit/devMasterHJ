#include <stdio.h>

int main(){
	int N;
	long long int M;
	int A[10000];
	scanf("%d %lld",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}

	int s = 0, end = 0, count = 0;
	long long int sum=0;

	while(1){
		if(sum >= M){
			sum -= A[s++];
		}
		else if(end == N){
			break;
		}
		else
			sum += A[end++];

		if(sum == M)
			count++;
	}

	printf("%d",count);
}
