#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int R,C;
char** arr;
char str[21] = "zzzzzzzzzzzzzzzzzzzz";
void check(char *word){
	if(strlen(word) >= 2){
		if(strcmp(word,str) <0 ){
			strcpy(str,word);
		}
	}
}
int main(){
	scanf("%d %d",&R,&C);
	arr = (char**)malloc(sizeof(char*)*R);
	for(int i=0;i<R;i++){
		arr[i] = (char*)malloc(sizeof(char)*(C+1));
		scanf("%s",arr[i]);
	}
	for(int i=0;i<R;i++){
		char word[21] = "";
		int idx = 0;
		for(int j=0;j<C+1;j++){
			if(j==C || arr[i][j] == '#'){
				word[idx] = '\0';
				check(word);
				idx = 0;
			}
			else word[idx++] = arr[i][j];
		}
	}

	for(int i=0;i<C;i++){
		char word[21] = "";
		int idx = 0;
		for(int j=0;j<R+1;j++){
			if(j == R || arr[j][i] == '#'){
				word[idx] = '\0';
				check(word);
				idx = 0;
			}
			else word[idx++] = arr[j][i];
		}
	}
	printf("%s",str);
}
