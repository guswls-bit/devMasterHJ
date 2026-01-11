#include <stdio.h>
#include <stdlib.h>

int* heap;
int N,heap_size=0;

void push(int data){
	heap_size++;
	int i = heap_size;
	
	while(i!=1&&(data > heap[i/2])){
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = data;
}

int pop(){
	if(!heap_size) return 0;
	int temp = heap[heap_size];	
	int result = heap[1];
	heap_size--;

	int parent = 1;
	int child = 2;

	while(child <= heap_size){
		if((child<heap_size)&&(heap[child] <heap[child+1])){
			child++;
		}
		if(temp >= heap[child]){
			break;
		}

		heap[parent] = heap[child];

		parent = child;
		child = child*2;
	}
	heap[parent] = temp;
	return result;

}

int main(){
	int a;
	scanf("%d",&N);
	heap = (int*)malloc(sizeof(int)*(N+10));
	for(int i=0;i<N;i++){
		scanf(" %d",&a);
		if(!a) printf("%d\n",pop());
		else push(a);	
	}
	return 0;
}
