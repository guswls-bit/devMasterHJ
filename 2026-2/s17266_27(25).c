#include <stdio.h>

int main(){
	int N,M;
	scanf("%d",&N);
	scanf("%d",&M);
	int x[100000];
	for(int i=0;i<M;i++){
		scanf("%d",&x[i]);
	}

	int ans = x[0];

	for(int i = 1;i<M;i++){
		int gap = x[i] - x[i-1];
		int height = (gap + 1) /2;
		if(height > ans) ans = height;
	}

	if(N - x[M-1] > ans) ans = N - x[M-1];

	printf("%d",ans);
}
