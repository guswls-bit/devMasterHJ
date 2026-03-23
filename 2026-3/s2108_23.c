#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
int* arr;

int compare(const void *a, const void *b){
	return *(int*)a - *(int *)b;
}


int main(){
	scanf("%d",&N);
	arr = (int*)malloc(sizeof(int*)*N);
	int min=-4001,max=4001;
	double sum = 0;
	int count[8001] = {0};
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		count[arr[i]+4000]++;
		sum += arr[i];
	}
	printf("%d\n",(int)round(sum/N));
	qsort(arr,N,sizeof(int),compare);	
	printf("%d\n",arr[N/2]);
	int bin = -1;
	int bin_num = 0;
	for(int i=0;i<8001;i++){
		if(bin_num < count[i]){
			bin = i;
			bin_num = count[i];
		}
	}
	int flag = 1;
	for(int i=0;i<8001;i++){
		if(bin_num == count[i]){
			if(flag==0){
				bin = i;
				break;
			}
			flag = 0;
		}
	}
	printf("%d\n",bin-4000);
	printf("%d\n",arr[N-1]-arr[0]);
	
}
