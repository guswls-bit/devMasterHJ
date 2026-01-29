#include <stdio.h>
#include <stdlib.h>

#define MAX 100001
#define DEQUE_SIZE 300000

int visit[MAX];
int deque[DEQUE_SIZE];
int head = 150000;
int tail = 150000;

int N,K;

void push_front(int x){
	deque[--head] = x;
}

void push_back(int x){
	deque[tail++] = x;
}

int pop_front(){
	return deque[head++];
}

int is_empty(){
	return head == tail;
}

int main(){
	scanf("%d %d",&N,&K);
	for(int i=0;i<MAX;i++){
		visit[i] = -1;
	}	

	push_back(N);
	visit[N] = 0;
	int cur;
	while(!is_empty()){
		cur = pop_front();

		if(cur == K){
			break;
		}

		int next = cur * 2;
		if(next < MAX && visit[next] == -1){
			visit[next] = visit[cur];
			push_front(next);
		}

		next = cur - 1;
		if(next >= 0 && visit[next] == -1){
			visit[next] = visit[cur] + 1;
			push_back(next);
		}

		next = cur + 1;
		if(next < MAX && visit[next] == -1){
			visit[next] = visit[cur] + 1;
			push_back(next);
		}
	}
	printf("%d",visit[cur]);
	return 0;
}
