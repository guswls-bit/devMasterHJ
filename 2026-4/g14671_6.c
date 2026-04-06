#include <stdio.h>

int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	
	int check[2][2] = {0,0,0,0};

	for(int i=0;i<k;i++){
		int r,c;
		scanf("%d %d",&r,&c);
		
		check[r%2][c%2] = 1;
	}
	if(check[0][0] && check[0][1] && check[1][0] && check[1][1]) printf("YES");
	else printf("NO");
}
