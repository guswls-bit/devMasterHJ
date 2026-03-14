#include <stdio.h>
#include <stdlib.h>

int main(){
	int* arr = (int*)calloc(30,sizeof(int));
	int x;
	for(int i=0;i<28;i++){
		scanf("%d",&x);
		arr[x-1] = 1;
	}

	for(int i=0;i<30;i++){
		if(!arr[i]) printf("%d\n",i+1);
	}
}
