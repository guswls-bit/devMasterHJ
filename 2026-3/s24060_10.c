#include <stdio.h>
#include <stdlib.h>

int* arr;
int N,K;
int save_count=0;
int* temp;
void merge(int p,int q,int r){
	int i = p;
	int j = q+1;
	int t = 1;
	while(i<= q && j <= r){
		if(arr[i] <= arr[j]){
			temp[t++] = arr[i++];
		}
		else temp[t++] = arr[j++];
	}
	while(i<=q) temp[t++] = arr[i++];
	while(j<=r) temp[t++] = arr[j++];

	i = p, t = 1;
	while(i<=r) {arr[i++] = temp[t++];save_count++;if(save_count==K){printf("%d",temp[t-1]);return;}}
}

void merge_sort(int p, int r){
	if(save_count==K) return;
        if(p<r){
                int q = (p+r)/2;
                merge_sort(p,q);
                merge_sort(q+1,r);
                merge(p,q,r);
		if(save_count==K) return;
        }
}

int main(){
	scanf("%d %d",&N,&K);
	arr = (int*)malloc(sizeof(int)*N);
	temp = (int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	merge_sort(0,N-1);
	if(save_count < K) printf("-1");
}
