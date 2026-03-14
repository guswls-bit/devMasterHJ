#include <stdio.h>
#include <stdlib.h>

int N,K;
int count=0;

void selection_sort(int* arr){
	for(int i=N-1;i>0;i--){
		int max = arr[i];
		int max_idx = i;
		for(int j=0;j<i;j++){
			if(arr[j] > max){
				max = arr[j];
				max_idx = j;
			} 
		}
		if(max_idx != i){
			arr[max_idx] = arr[i];
			arr[i] = max;
			count++;
			if(count == K){
				for(int k=0;k<N;k++) printf("%d ",arr[k]);
				return;
			}
		}
	}
}

int main(){
	scanf("%d %d",&N,&K);
	int* arr;
	arr = (int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}

	selection_sort(arr);
	
	if(count<K) printf("-1");
	return 0;
}
