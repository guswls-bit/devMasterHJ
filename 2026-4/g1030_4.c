#include <stdio.h>
#include <stdlib.h>

int s, N, K ,R[2], C[2];
int solve(int size, int r, int c){
	if(size == 1) return 0;
	int unit_size = size / N;
	
	int row = r / unit_size;
	int col = c / unit_size;

	int s = (N-K) / 2;
	int e = s + K;
	
	if((s <= row&&row < e) &&(s <= col&&col < e)) return 1;

	return solve(unit_size,r%unit_size,c%unit_size);
}
int main(){
	scanf("%d %d %d %d %d %d %d",&s,&N,&K,&R[0],&R[1],&C[0],&C[1]);
	int size = 1;
	for(int i=0;i<s;i++){
		size *= N;
	}
	for(int i=R[0];i<=R[1];i++){
		for(int j=C[0];j<=C[1];j++){
			printf("%d",solve(size,i,j));
		}
		printf("\n");
	}	
}
