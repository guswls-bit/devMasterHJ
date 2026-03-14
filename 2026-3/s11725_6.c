#include <stdio.h>
#include <stdlib.h>

struct Node{
	int dest;
	struct Node* next;	
};
typedef struct Node Node;
int N;
Node** graph;
int* res;
int* visit;

void addedge(int u,int v){
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = graph[u];
	node->dest = v;
	graph[u] = node;
}

void search(){
	int* queue = (int*)malloc(sizeof(int)*(N+1));
	int front = 0,rear = 0;
	visit[1] = 1;
	Node* cur = graph[1];
	while(cur != NULL){
		queue[front++] = cur->dest;
		res[cur->dest] = 1;
		cur = cur->next;
	}
	while(front>rear){
		int now = queue[rear];
		Node* cur = graph[now];
		visit[now] = 1;
		while(cur != NULL){
			if(visit[cur->dest]==0){
				queue[front++] = cur->dest;
				res[cur->dest] = now;  
			}
			cur = cur->next;
		}
		rear++;
	}
}

int main(){
	scanf("%d",&N);
	graph = (Node**)malloc(sizeof(Node*)*(N+1));
	res = (int*)malloc(sizeof(int)*(N+1));
	visit = (int*)calloc(N+1,sizeof(int));
	res = (int*)malloc(sizeof(int)*(N+1));
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		addedge(a,b);
		addedge(b,a);
	}
	search();
	for(int i=2;i<=N;i++){
		printf("%d\n",res[i]);
	}
}
