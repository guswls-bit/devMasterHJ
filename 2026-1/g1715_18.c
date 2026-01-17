#include <stdio.h>
#include <stdlib.h>

int N;
int* heap;
int heap_size=0;

void push(int data){
	heap_size++;
	int i = heap_size;
	while((i != 1)&&(data<heap[i/2])){
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = data;
}

int pop(){
	int i = heap[1];
	int temp = heap[heap_size--];
	int parent = 1, child = 2;

	while(child <= heap_size){
		if((child < heap_size)&&(heap[child] > heap[child + 1]))
			child++;
		if(temp <= heap[child]) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return i;
}

int search(){
	int sum = 0,a,b;
	while(heap_size != 1){
		a = pop();
		b = pop();
		sum += a+b;
		push(a+b);
	}
	return sum;
}

int main(){
	int a;
	scanf("%d",&N);
	heap = (int*)malloc(sizeof(int)*(N+10));
	for(int i=0;i<N;i++) {scanf("%d",&a);push(a);}
	printf("%d",search());
	return 0;
}
