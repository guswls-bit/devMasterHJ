#include <stdio.h>
#include <stdlib.h>

int N, flag=0,diff=0;
int* arr;
int* res;
void check(int i, int val){
	if(arr[i] != res[i]) diff--;
	arr[i] = val;
	if(arr[i] != res[i]) diff++;
}

int partition(int p, int r){
        int x = arr[r];
        int i = p-1;
        for(int j=p;j<r;j++){
                if(arr[j] <= x){
                        ++i;
                        int a = arr[i], b = arr[j];
			check(i,b);
			check(j,a);	
			if(diff==0){
				flag = 1;
				return 0;
			}
                }
        }
        if(i+1 != r){
		int a = arr[i+1], b = arr[r];
		check(i+1,b);
		check(r,a);
		if(diff == 0){
			flag = 1;
			return 0;
		}
        }
        return i+1;
}

void quick_sort(int start, int end){
	if(flag == 1) return;
        if(start<end){
                int pivot = partition(start,end);
                if(flag == 1) return;
		quick_sort(start, pivot-1);
                quick_sort(pivot+1,end);
        }
}

int main(){
        scanf("%d",&N);
        arr = (int*)malloc(sizeof(int)*N);
	res = (int*)malloc(sizeof(int)*N);
        for(int i=0;i<N;i++){
                scanf("%d",&arr[i]);
        }
	for(int i=0;i<N;i++){
		scanf("%d",&res[i]);
	}
	for(int i=0;i<N;i++){
		if(arr[i] != res[i]) diff++;
	}
	if(diff == 0){
       		printf("1");
        	return 0;
    	}
        quick_sort(0,N-1);
        printf("%d",flag);
}
