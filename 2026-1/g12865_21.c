#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int W;
	int V;
}Item;

int N,K;
Item* bag;
int* dp;

#define MAX(a,b) ((a) > (b) ? (a) : (b))


int main(){
	scanf("%d %d",&N,&K);
	bag = (Item*)malloc(sizeof(Item)*N);
	dp = (int*)calloc(K+1,sizeof(int));
	for(int i=0;i<N;i++){
		scanf("%d %d",&bag[i].W,&bag[i].V);
	}
	for(int i=0;i<N;i++){
		int w = bag[i].W;
		int v = bag[i].V;

		for(int j=K;j>=w;j--){
			dp[j] = MAX(dp[j],dp[j-w] + v);
		}
	}
	printf("%d",dp[K]);
	return 0;
}
