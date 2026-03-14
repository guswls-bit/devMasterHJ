#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	scanf("%d",&N);
	int now = 666;
	while(N){
		int a = now;
		int flag = 0;
		for(int i=a%10;a!=0;i=a%10){
			if(i == 6) flag++;
			else flag = 0;

			if (flag == 3) break;

			a /= 10;
		}
		if(flag == 3) N--;
		if(N==0) break;
		now++;
	}
	printf("%d",now);
}
