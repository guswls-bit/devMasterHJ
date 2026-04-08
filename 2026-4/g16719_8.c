#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[101];
int* visit;

void printchar(){
	for(int i=0;i<strlen(str);i++){
		if(visit[i]) printf("%c",str[i]);
	}
	printf("\n");
}

void solve(int start, int end){
	if(start > end) return;
	
	char min_char = str[start];
	int min_idx = start;
	for(int i=start+1;i<=end;i++){
		if(min_char > str[i]){
			min_char = str[i];
			min_idx = i;
		}
	}
	if(!visit[min_idx]){	
		visit[min_idx] = 1;
		printchar();
	}
	solve(min_idx+1,end);
	solve(start,min_idx-1);
}

int main(){
	scanf("%s",str);
	visit = (int*)calloc(strlen(str),sizeof(int));
	solve(0,strlen(str)-1);
}
