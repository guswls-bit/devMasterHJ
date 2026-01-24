#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char inorder[500];
char preorder[500];
int len;

void search(int idx, int start, int end){
	if(start >= end) return;
	int temp = -1;
	for(int i=start;i<end;i++){
		if(preorder[idx] == inorder[i]){
			temp = i;
			break;
		}
	}
	if(temp == -1) return;
	search(idx+1,start,temp);
	search(idx+1+(temp-start),temp+1,end);
	printf("%c",preorder[idx]);
	return;
}

int main(){
        while(scanf("%s %s",preorder,inorder)!=EOF){
                len = strlen(preorder);
                search(0,0,len);
		printf("\n");
        }
}
