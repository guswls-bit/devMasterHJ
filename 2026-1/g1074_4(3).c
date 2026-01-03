#include <stdio.h>
#include <stdlib.h>
void find(int num,long long int pedding, int row, int col);

int N,r,c;

int main(){
	scanf("%d %d %d",&N,&r,&c);
	int root=1;
	for(int i=0;i<N;i++) root *= 2; 
	find(0,root,0,0);
	return 0;	
}

void find(int num, long long int pedding, int row, int col){
	if(c==col&&r==row) {printf("%d",num);return;}
	pedding /=2;
	if((r<row+pedding)&&(c<col+pedding)) find(num,pedding,row,col);
	else if((r<row+pedding)&&(c>=col+pedding)) find(num+(pedding*pedding),pedding,row,col+pedding);
	else if((r>=row+pedding)&&(c<col+pedding)) find(num+(pedding*pedding*2),pedding,row+pedding,col);
	else find(num+(pedding*pedding*3),pedding,row+pedding,col+pedding);

}
