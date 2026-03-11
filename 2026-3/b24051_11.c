#include <stdio.h>
#include <stdlib.h>

int N, K;
int* arr;
int swap_count=0;
void insertion_sort(){
	for(int i=1;i<N;i++){
		int loc = i-1;
		int newItem = arr[i];

		while(0<=loc && newItem < arr[loc]){
			arr[loc+1] = arr[loc];
			loc--;
			swap_count++;
			if(swap_count==K){
				printf("%d",arr[loc+1]);
				return;
			}
		}
		if(loc+1 != i) {
			arr[loc+1] = newItem;
			swap_count++;
                        if(swap_count==K){
                                printf("%d",newItem);
                                return;
                        }
		}
	}
	printf("-1");	
}

int main(){
	scanf("%d %d",&N,&K);
	arr = (int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++) scanf("%d",&arr[i]);
	insertion_sort();
}
