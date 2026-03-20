#include <stdio.h>
#include <stdlib.h>

int* arr;
int count=0;
int K,N;
void swap(int a,int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        count++;
        if(count == K){ 
		for(int i=1;i<N+1;i++){
			printf("%d ",arr[i]);
		}
	}
}
void heapify(int k, int n){
        if(count == K) return;
        int left = 2*k;
        int right = 2*k + 1;
        int smaller;

        if(right <= n){
                if(arr[left] < arr[right]){
                        smaller = left;
                }
                else smaller = right;
        }
        else if(left <= n) smaller = left;
        else return;

        if(arr[smaller] < arr[k]){
                swap(k,smaller);
                if(count == K) return;
                heapify(smaller,n);
        }
}

void build_min_heap(int n){
        for(int i=n/2;i>0;i--){
                heapify(i,n);
        }
}

void heap_sort(int n){
        build_min_heap(n);
        for(int i=n;i>1;i--){
                swap(1,i);
                if(count == K) return;
                heapify(1,i-1);
                if(count == K) return;
        }
}

int main(){
        int n,k;
        scanf("%d %d",&n,&K);
	N = n;
        arr = (int*)malloc(sizeof(int)*(n+1));
        for(int i=1;i<n+1;i++) scanf("%d",&arr[i]);
        heap_sort(n);
        if(count<K) printf("-1");
        free(arr);
        return 0;
}

