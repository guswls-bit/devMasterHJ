#include <stdio.h>
#include <stdlib.h>

int N, K,swap_count=0;
int* arr;


int partition(int p, int r){
        int x = arr[r];
        int i = p-1;
        for(int j=p;j<r;j++){
                if(arr[j] <= x){
                        ++swap_count;
                        ++i;
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
			if(swap_count == K){ for(int k=0;k<N;k++) printf("%d ",arr[k]);return 0;}

                }
        }
        if(i+1 != r){
                swap_count++;
                int temp = arr[i+1];
                arr[i+1] = arr[r];
                arr[r] = temp;
		if(swap_count == K){ for(int k=0;k<N;k++) printf("%d ",arr[k]);return 0;}
        }
        return i+1;
}

void quick_sort(int start, int end){
        if(swap_count==K) return;
        if(start<end){
                int pivot = partition(start,end);
                if(swap_count==K) return;
                quick_sort(start, pivot-1);
                quick_sort(pivot+1,end);
        }
}

int main(){
        scanf("%d %d",&N,&K);
        arr = (int*)malloc(sizeof(int)*N);
        for(int i=0;i<N;i++){
                scanf("%d",&arr[i]);
        }
        quick_sort(0,N-1);
        if(swap_count<K) printf("-1");
}

