#include <stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int cur = N;
	int count = 0;
	
	do{
		int a = cur/10;
		int b = cur%10;
		cur = (b*10)+(a+b)%10;
		count++;
	}while(cur != N);
	printf("%d",count);

}
