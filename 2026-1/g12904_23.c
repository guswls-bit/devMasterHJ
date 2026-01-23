#include <stdio.h>
#include <stdlib.h>

char S[1001];
char T[1001];

int flag = 0;
int S_len;
void search(int T_len){
	if(flag) return;
	if(T_len == S_len){
		for(int i=0;i<S_len;i++){
			if(S[i] != T[i]){
				return;
			}
		}
		flag = 1;
		return;
	}
	if(T[T_len-1] == 'A'){
		search(T_len-1);
	}
	if(flag) return;
	if(T[T_len-1] == 'B'){
		char temp[1001];
		for(int i=0;i<T_len;i++) temp[i] = T[i];
		for(int i=0;i<T_len-1;i++) T[i] = temp[T_len-2-i];
		search(T_len-1);
		for(int i=0;i<T_len;i++) T[i] = temp[i];
	}
}

int main(){
	scanf("%s",S);
	scanf(" %s",T);
	for(S_len=0;S[S_len]!='\0';S_len++) ;
	int T_len;
	for(T_len=0;T[T_len]!='\0';T_len++) ;
	search(T_len);
	printf("%d",flag);
	return 0;
}
