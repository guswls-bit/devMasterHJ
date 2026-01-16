#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
}Meeting;


int N;
Meeting* A;

void swap(Meeting* a, Meeting* b){
	Meeting temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int low, int high){
	Meeting pivot = A[high];
	int i = (low - 1);

	for(int j = low; j<high;j++){
		if(A[j].end < pivot.end || (A[j].end == pivot.end && A[j].start < pivot.start)){
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[high]);
	return (i+1);
}

void quickSort(int low, int high){
	if(low<high){
		int pi = partition(low,high);

		quickSort(low,pi-1);
		quickSort(pi+1,high);
	}
}
int main(){
	scanf("%d",&N);	
	A = (Meeting*)malloc(sizeof(Meeting)*N);
	for(int i=0;i<N;i++){
		scanf("%d %d",&A[i].start,&A[i].end);
	}
	quickSort(0,N-1);
	int count =0;
	int l = 0;
	for(int i=0;i<N;i++){
		if(A[i].start >= l){
			count++;
			l = A[i].end;
		}
	}

	printf("%d",count);
	return 0;
}
