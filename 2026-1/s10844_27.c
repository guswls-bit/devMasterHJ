#include <stdio.h>
#include <stdlib.h>

int N;
int num[10];

int main(){
	scanf("%d",&N);
	num[0] = 0;
	for(int i=1;i<10;i++){
		num[i] = 1;
	}
	long long int num1[10];
	for(int j=1;j<N;j++){
		for(int i=0;i<10;i++){
			if(i == 0){
				num1[i] = num[i+1];
			}
			else if(i == 9){
				num1[i] = num[i-1];
			}
			else{
				num1[i] = num[i-1];
				num1[i] += num[i+1];
			}
		}
		for(int i=0;i<10;i++){
			num[i] = num1[i] % 1000000000;
		}
	}
	long long int sum = 0;
	for(int i=0;i<10;i++){
		sum += num[i];
		sum = sum % 1000000000;
	}
	printf("%d",sum);

}
