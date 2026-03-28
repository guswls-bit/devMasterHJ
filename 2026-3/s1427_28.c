#include <stdio.h>
#include <string.h>

char s[1000];
int count[10];

int main(){
	scanf("%s",s);
	for(int i=0;i<10;i++){
		count[i] = 0;
	}
	for(int i=0;i<strlen(s);i++){
		count[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<count[i];j++){
			printf("%d",i);
		}
	}
}
