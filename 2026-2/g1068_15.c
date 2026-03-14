#include <stdio.h>
#include <stdlib.h>

int N;
int tree[50][50];
int child[50];
int del, root;
int leaf = 0;

void dfs(int node){
	int temp = 0;
	
	for(int i=0;i<child[node];i++){
		int child_temp = tree[node][i];

		if(child_temp == del) continue;

		temp++;
		dfs(child_temp);
	}

	if(temp == 0){
		leaf++;
	}
}

int main(){
	scanf("%d",&N);
	int a;
	for(int i=0;i<N;i++){
		scanf("%d",&a);
		if(a==-1) root = i;
		else tree[a][child[a]++] = i;
	}	
	scanf("%d",&del);
	
	if(del == root) printf("0");
	else {dfs(root);printf("%d",leaf);}
}
