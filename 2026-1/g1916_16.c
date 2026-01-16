#include <stdio.h>
#include <stdlib.h>
#define INF 200000000

struct Node{
	int weight;
	int to;
	struct Node* next;
};
typedef struct Node Node;
typedef struct{
	int d;
	int u;
}Element;

Node** graph;
int V,E,start,end;
Element* heap;
int heap_size = 0;

void push(int u, int d){
	heap_size++;
	int i = heap_size;
	while((i != 1)&&(d<heap[i/2].d)){
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i].u = u;
	heap[i].d = d;
}

Element pop(){
	Element i = heap[1];
	Element temp = heap[heap_size--];
	int parent = 1, child = 2;
	
	while(child<= heap_size){
		if((child<heap_size)&&(heap[child].d > heap[child+1].d))
			child++;
		if (temp.d <= heap[child].d) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return i;
}

int dijk(){
	int* result = (int*)malloc(sizeof(int)*(V+1));
	int* visit = (int*)malloc(sizeof(int)*V);
	for(int i=0;i<V;i++) {
		result[i+1] = INF;
		visit[i] = 0;
	}
	result[start] = 0;
	push(start,0);
	
	while(heap_size>0){
		Element c = pop();
		int u = c.u;
		int d = c.d;
		
		if(d>result[u]) continue;
		
		Node* curr = graph[u-1];
		while(curr != NULL){
			int v = curr->to;
			int w = curr->weight;

			if(result[u] + w <result[v]){
				result[v] = result[u] + w;
				push(v,result[v]);
			}
			curr = curr->next;
		}
	}
	return result[end];
}


void add(int u, int v, int w){
	Node* node = (Node*)malloc(sizeof(Node));
	node->weight = w;
	node->to = v;
	node->next = graph[u-1];
	graph[u-1] = node;
}


int main(){
	scanf("%d %d",&V,&E);
	graph = (Node**)malloc(sizeof(Node*)*V);
	heap = (Element*)malloc(sizeof(Element)*(E+10));
	int u,v,w;
	for(int i=0;i<V;i++) graph[i] = NULL;
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
	}
	scanf("%d %d",&start,&end);
	printf("%d",dijk());
	return 0;
}
