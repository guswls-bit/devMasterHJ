#include <stdio.h>

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int c=0,d=0;
	while(a!=0||b!=0){
		if(a!=0){
			c *= 10;
			c += a%10;
			a /= 10;
		}
		if(b!=0){
			d *= 10;
			d += b%10;
			b /= 10;
		}
	}
	int sum = c+d;
	int result=0;
	while(sum > 0){
 		result = result * 10 + sum % 10;
    		sum /= 10;
	}
	printf("%d",result);
}
