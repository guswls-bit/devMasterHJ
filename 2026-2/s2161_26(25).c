#include <stdio.h>

int N;

int main(){
	scanf("%d",&N);
	int queue[1000001];
	int front = 0, rear = N;
	for(int i=0;i<N;i++){
		queue[i] = i+1;
	}

	while(front < rear){
		printf("%d ",queue[front++]);
		if(front < rear){
			queue[rear++] = queue[front++];
		}
	}
}
