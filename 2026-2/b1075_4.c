#include <stdio.h>

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	for(int i=0;i<100;i++){
		if((a - (a%100) + i)%b == 0) {
			printf("%02d",i);
			return 0;
		}
	}
}
