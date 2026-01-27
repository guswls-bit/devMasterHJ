#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int A;
	int B;
}Node;

int N;
Node* arr;
int* dp;
void sort(){
	Node Temp;
	for(int i=0;i<N-1;i++){
		for(int j=0;j<N-1-i;j++){
			if(arr[j].A > arr[j+1].A){
				Temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = Temp;
			}
		}
	}
	return;
}

int main(){
	scanf("%d",&N);
	arr = (Node*)malloc(sizeof(Node)*N);
	dp = (int*)malloc(sizeof(int)*(N+1));
	for(int i=0;i<N;i++){
		scanf("%d %d",&arr[i].A,&arr[i].B);
	}
	sort();

	int max = 0;
	for(int i=0;i<N;i++){
		dp[i] = 1;
		for(int j=0;j<N;j++){
			if(arr[i].B > arr[j].B){
				if(dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
				}
			}	
		}

		if(max < dp[i]) max = dp[i];
	}

	printf("%d",N-max);
	return 0;
}
