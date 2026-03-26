#include <stdio.h>
#include <stdlib.h>

int N,M;
int** arr;

int main(){
	scanf("%d %d",&N,&M);
	arr =(int**)malloc(sizeof(int*)*N);
	for(int i=0;i<N;i++){
		arr[i] = (int*)malloc(sizeof(int)*M);
		for(int j=0;j<M;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int K;
	scanf("%d",&K);
	int i,j,x,y;
	for(int a=0;a<K;a++){
		int sum = 0;
		scanf("%d %d %d %d",&i,&j,&x,&y);
		for(int b = i;b<=x;b++){
			for(int c = j;c<=y;c++){
				sum += arr[b-1][c-1];
			}
		}
		printf("%d\n",sum);
	}
}
