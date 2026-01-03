#include <stdio.h>
#include <stdlib.h>
long long int sort();
int partition(int p, int r);
void quick_sort(int left, int right);

int N;
int* arr;

int main(){
	scanf(" %d",&N);
	arr = (int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++){
			scanf(" %d",&arr[i]);
	}	
	printf("%lld",sort());
	free(arr);
	return 0;
}

long long int sort(){

	quick_sort(0, N-1);
	long long int sum=0;
	for(int i=0;i<N;i++){
		sum +=((arr[i]-1 - i)>0)?(arr[i]-1-i):(i+1-arr[i]);
	}
	return sum;
}

int partition (int p, int r){
    int low, high;
    int pivot = arr[p]; 

    low = p + 1; 
    high = r;

    while(low <= high){
        while(low <= r && arr[low] < pivot) low++; 
        
        while(arr[high] > pivot) high--; 

        if (low <= high){ 
            int temp = arr[low]; 
            arr[low] = arr[high];
            arr[high] = temp;
            low++; 
            high--;
        }
    }

    int temp = arr[p];
    arr[p] = arr[high];
    arr[high] = temp;

    return high; 
} 
void quick_sort(int left, int right){
    if (left < right){
        int pivot = partition(left, right);
 
        quick_sort(left, pivot-1);
        quick_sort(pivot+1, right);
    }
}
