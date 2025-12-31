#include <stdio.h>
#include <stdlib.h>
void sort();
void N_M(int point);

int n,m;
int* arr;
int* vis;
int* res;

int main(){
	scanf("%d %d",&n,&m);
	arr=(int*)malloc(sizeof(int)*n);	
	res = (int*)malloc(sizeof(int) * m);
   	vis = (int*)calloc(n, sizeof(int));
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);	
	}
	
	sort();
	N_M(0);

	return 0;
}

void sort(){
	int temp = 0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;	
			}		
		}
	}
	return;
}

void N_M(int point){
	if(point == m){
        for(int i = 0; i < m; i++){
            printf("%d ", res[i]);
        }
        printf("\n");
        return;
    }
	int last_num = -1; 
    
    for(int i = 0; i < n; i++){
        if(!vis[i] && last_num != arr[i]){
            res[point] = arr[i]; 
            last_num = arr[i];      
            
            vis[i] = 1;      
            N_M(point + 1);       
            vis[i] = 0;         
        }
    }
}
