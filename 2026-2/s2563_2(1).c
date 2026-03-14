#include <stdio.h>

int arr[100][100];

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			arr[i][j] = 0;
		}
	}
	while(N--){
		int a,b;
		scanf("%d %d",&a,&b);
		for(int i=a;i<a+10;i++){
			for(int j=90-b;j<100-b;j++){
				arr[i][j] = 1;
			}
		}
	}
	int sum = 0;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(arr[i][j]) sum++;	
		}
	}
	printf("%d",sum);
	return 0;
}
