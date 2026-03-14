#include <stdio.h>
#include <string.h>

int main(){
	int N;
	scanf("%d",&N);
	char a[100];
	while(N--){
		int b;
		scanf("%d %s",&b,a);
		for(int i=0;i<strlen(a);i++){
			for(int j=0;j<b;j++){
				printf("%c",a[i]);
			}
		}
		printf("\n");
	}
}
