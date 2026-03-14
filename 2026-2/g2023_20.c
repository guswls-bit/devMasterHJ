#include <stdio.h>
int N;

int isPrime(int num){
	if(num<2) return 0;
	for(int i=2;i*i<=num;i++){
		if(num%i == 0) return 0;
	}
	return 1;
}

void back(int num,int jari){
	if(jari == N){
		printf("%d\n",num);
		return;
	}
	for(int i=1;i<=9;i+=2){
		int nextnum = num*10 + i;
		if(isPrime(nextnum)){
			back(nextnum,jari+1);
		}
	}

}

int main(){
	scanf("%d",&N);
	back(2,1);
	back(3,1);
	back(5,1);
	back(7,1);
	return 0;
}
