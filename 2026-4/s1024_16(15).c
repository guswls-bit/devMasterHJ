#include <stdio.h>
#include <stdlib.h>

int main(){
	long long N;
	int L;
	scanf("%lld%d",&N,&L);
	for(int i=L;i<=100;i++){
		long long t = (long long)i * (i-1)/2;
		if(N-t<0){
			break;
		}
		if((N-t)%i ==0){
			long long x = (N-t)/i;
			for(int j=0;j<i;j++){
				printf("%lld ",x+j);
			}
			return 0;
		}
	}
	printf("-1");
}
