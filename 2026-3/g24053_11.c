#include <stdio.h>
#include <stdlib.h>

int N, diff=0;
int* arr;
int* res;
void insertion_sort(){
        for(int i=1;i<N;i++){
                int loc = i-1;
                int newItem = arr[i];

                while(0<=loc && newItem < arr[loc]){
			if(arr[loc+1] != res[loc+1]) diff--;
                        arr[loc+1] = arr[loc];
                        diff += (arr[loc+1] != res[loc+1])?1:0;
			loc--;
			if(diff==0){
				printf("1");
				return;
			}
                }
                if(loc+1 != i) {
                        if(arr[loc+1] != res[loc+1]) diff--;
			arr[loc+1] = newItem;
                	diff += (arr[loc+1] != res[loc+1])?1:0;
			if(diff==0){
                                printf("1");
                                return;
                        }
		}
        }
	printf("0");
}

int main(){
        scanf("%d",&N);
        arr = (int*)malloc(sizeof(int)*N);
        res = (int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++) scanf("%d",&arr[i]);
        for(int i=0;i<N;i++) scanf("%d",&res[i]);
	for(int i=0;i<N;i++) if(arr[i] != res[i]) diff++;
	if(diff==0) {printf("1"); return 0;}
	insertion_sort();
}
