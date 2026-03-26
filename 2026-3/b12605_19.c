#include <stdio.h>
#include <string.h>

int main(){
	int N;
	scanf("%d",&N);
	char s[26];
	char rs[26];
	int count = 1;
	while(N--){
		scanf(" %[^\n]s",s);
		int len = strlen(s);
		int start=0;
		for(int i=0;i<strlen(s)+1;i++){
			if(s[i] == 0x20 || s[i] == '\0'){
				for(int j=0;j<i-start;j++){
					rs[len-i+j] = s[j+start];
				}
				rs[len-i-1] = ' ';
				start = i+1;
			}
		}
		rs[len] = 0;
		printf("Case #%d: %s\n",count++,rs);
	}
}
