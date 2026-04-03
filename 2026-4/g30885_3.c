#include <stdio.h>
#include <stdlib.h>

long long int size[500001];
int prv[500001];
int nxt[500001];
int N,NN;
int head = 1;

void solve(){
	int cur=1;
	while(NN!=1){
		long long int sum = 0;
		if(prv[cur] != 0 && size[cur] >= size[prv[cur]]){
			sum += size[prv[cur]];
			if(head == prv[cur]) head = cur;
			if(prv[prv[cur]] != 0) nxt[prv[prv[cur]]] = cur;
			prv[cur] = prv[prv[cur]];
			NN--;
		}
		if(nxt[cur] != N+1 && size[cur] >= size[nxt[cur]]){
			sum += size[nxt[cur]];
			if(nxt[nxt[cur]] != N+1) prv[nxt[nxt[cur]]] = cur;
			nxt[cur] = nxt[nxt[cur]];
			NN--;
		}
		size[cur] += sum;
		if(nxt[cur] == N+1) cur = head;
		else cur = nxt[cur];		
	}
	printf("%lld\n%d",size[cur],cur);
}

int main(){
	scanf("%d",&N);
	NN = N;
	for(int i=1;i<=N;i++){
		int a;
		scanf("%d",&a);
		size[i] = (long long int)a;
		prv[i] = i-1;
		nxt[i] = i+1;
	}
	solve();
}
