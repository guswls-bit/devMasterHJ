#include <stdio.h>
#include <string.h>

char arr[51];
char result[51];

int main(){
	scanf("%s",arr);
	int count=0;
	for(int i=0;i<=strlen(arr);i++){
		if(arr[i] == 'X') count++;
		else{
			if(count%2 != 0){
				printf("-1");
				return 0;
			}
			while(count >= 4){
				strcat(result,"AAAA");
				count -= 4;
			}
			while(count >= 2){
				strcat(result,"BB");
				count -= 2;
			}
			if(arr[i] == '.'){
				strcat(result,".");
			}
		}	
	}
	printf("%s",result);
}
