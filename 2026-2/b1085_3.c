#include <stdio.h>

int x,y,w,h;

int main(){
	scanf("%d %d %d %d",&x,&y,&w,&h);
	int min=w-x;
	min = (min>x)?x:min;
	min = (min>h-y)?(h-y):min;
	min = (min>y)?y:min;
	printf("%d",min);
	return 0;
}
