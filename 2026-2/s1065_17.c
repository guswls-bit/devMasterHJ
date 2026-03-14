#include <stdio.h>

int main(){
	int N;
	scanf("%d",&N);

	int count = 0;
	for(int i=1;i<=N;i++){
		if(i<100){
			count++;
		}
		else{
			int a = i/100;
			int b = (i/10)%10;
			int c = i%10;

			if((b-a)==(c-b)){
				count++;
			}
		}
	}

	printf("%d",count);
}
