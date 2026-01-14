#include <stdio.h>
#include <stdlib.h>

char S[51];
char T[51];
int flag=0;
int S_len,T_len;

void search(char* cur){
	if(flag) return;
	if(S_len==T_len){
		for(int i=0;i<S_len;i++){
			if(S[i] != cur[i]) return;
		}
		flag = 1;
		return;
	}
	if(T[T_len-1] == 'A'){
		T_len--;
		cur[T_len] = '\0';
		search(cur);
		cur[T_len] = 'A';
		T_len++;
	}
	if(flag) return;
	if(T[0] == 'B'){
		char result[51];
		for(int i=0;i<T_len;i++) result[i] = cur[i];
		for(int i=0;i<T_len;i++) cur[i] = result[T_len-1-i];
		T_len--;
		cur[T_len] = '\0';
		search(cur);
		T_len++;	
		for(int i=0;i<T_len;i++) cur[i] = result[i];
	}

}

int main(){
	scanf("%s",S);
	scanf(" %s",T);
	int i;
	for(i=0;S[i]!='\0';i++) ;
	S_len = i;
	for(i=0;T[i]!='\0';i++) ;
	T_len = i;
	search(T);
	printf("%d",flag);
	return 0;
}
