#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_st[1000001];
int prev_st[1000001];
int N,M;

void solve(){
	char cmd[3];
	int target;
	while(M--){
		scanf("%s",cmd);
		int i,j;
		if(strcmp(cmd, "BN") == 0){
			scanf("%d%d",&i,&j);
			target = next_st[i];
			printf("%d\n",target);
	
			next_st[i] = j;
			prev_st[j] = i;
			next_st[j] = target;
			prev_st[target] = j;
		}
		else if(strcmp(cmd,"BP")==0){
			scanf("%d%d",&i,&j);
			target = prev_st[i];
			printf("%d\n",target);
		
			next_st[target] = j;
			prev_st[j] = target;
			next_st[j] = i;
			prev_st[i] = j;
		}
		else if(strcmp(cmd,"CN")==0){
			scanf("%d",&i);
			target = next_st[i];
			printf("%d\n",target);
			
			int nt = next_st[target];
			
			next_st[i] = nt;
			prev_st[nt] = i;
		}
		else if(strcmp(cmd,"CP")==0){
			scanf("%d",&i);
			target = prev_st[i];
			printf("%d\n",target);
			
			int pt = prev_st[target];
			
			next_st[pt] = i;
			prev_st[i] = pt;
		}
	}
}

int main(){
	scanf("%d %d",&N,&M);
	int first=-1, prev=-1;
	for(int i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		if(i == 0){
			first = a;	
		}else{
			next_st[prev] = a;
			prev_st[a] = prev;
		}
		prev = a;
	}
	next_st[prev] = first;
	prev_st[first] = prev;
	solve();
}
