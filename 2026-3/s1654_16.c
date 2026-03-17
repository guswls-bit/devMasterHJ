#include <stdio.h>
#include <stdlib.h>

long long int K,N;
int* arr;

int main(){
	scanf("%d %d",&K,&N);
	arr = (int*)malloc(sizeof(int)*K);
	long long int max = -1;
	for(int i=0;i<K;i++){
		scanf("%d",&arr[i]);
		if(arr[i] > max) max = arr[i];
	}
	long long int start = 1, end = max;
	long long int mid ;
	while(start <= end){
		mid = (start + end) / 2;
		long long int len_count = 0;
		for(int i=0;i<K;i++){
			len_count += arr[i] / mid;
		}
		if(len_count >= N) start = mid + 1;
		else end = mid - 1;
	}
	printf("%d",end);
}
