#include <stdio.h>

int arr[1001][6];
int N;

int main(){
	scanf("%d",&N);
	int max = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<5;j++){
			scanf("%d",&arr[i][j]);
		}
		arr[i][5] = 0;
		for(int j=0;j<3;j++){
			for(int k=j+1;k<4;k++){
				for(int m=k+1;m<5;m++){
					int sum = arr[i][j] + arr[i][k] + arr[i][m];
					sum = sum%10;
					if(arr[max][5] <= sum){
						max = i;
						arr[i][5] = sum;
					}
				}
			}
		}
	}
	printf("%d",max+1);
	
}
