#include <stdio.h>

int main(){
	int x;
	scanf("%d",&x);
	
	int count=1;

	while(x>count){
		x -= count;
		count++;
	}

	if (count % 2 == 0) {
		printf("%d/%d", x, count - x + 1);
	} else {
    		printf("%d/%d", count - x + 1, x);
	}
}
