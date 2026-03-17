#include <stdio.h>
#include <stdlib.h>

typedef struct Edge Edge;
struct Edge{
	int start;
	int end;
	int weight;
};


int V,e;
int* parent;
Edge* E;

int compare(const void* a, const void* b){
	Edge* x = (Edge*)a;
	Edge* y = (Edge*)b;
	return x->weight - y->weight;
}

int find(int x){
	if(x==parent[x]){
		return x;
	}
	else{
		return parent[x] = find(parent[x]);
	}
}

void union_find(int a,int b){
	a = parent[a];
	b = parent[b];
	parent[a] = b;
}

void addEdge(int idx, int u,int v,int w){
	E[idx].start = u;
	E[idx].end = v;
	E[idx].weight = w;
}

void kruskal(){
	int j=0;
	int acc = 0;
	int a,b;
	int result = 0;
	while(acc != V-1){
		a = E[j].start;
		b = E[j].end;
		if(find(a) != find(b)){
			union_find(a,b);
			acc++;
			result += E[j].weight;
		}
		j++;
	}
	printf("%d",result);
}

int main(){
	scanf("%d %d",&V,&e);
	parent = (int*)malloc(sizeof(int)*(V+1));
	E = (Edge*)malloc(sizeof(Edge)*(e+1));
	for(int i=0;i<e;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		addEdge(i,a,b,c);
	}
	for(int i=1;i<V+1;i++){
		parent[i] = i;
	}
	qsort(E,e, sizeof(Edge), compare);

	kruskal();

}
