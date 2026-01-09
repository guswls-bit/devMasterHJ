#include <stdio.h>
#include <stdlib.h>
int bfs();

int visit[200001];
int queue[200001];
int rear=0,front=0;
int N,K;

int main(){
        scanf("%d %d",&N,&K);
        for(int i=0;i<200001;i++) visit[i] = 0;
        printf("%d",bfs()-1);
        return 0;
}

int bfs(){
        queue[front++] = N;
        visit[N] = 1;
        int now,count,depth =0;
        while(1){
                count = front;
                depth++;
                while(rear!=count){
                        now = queue[rear++];
                        if(now==K) return depth;
                        if(now-1>=0) {if(!visit[now-1]){queue[front++] = now-1;visit[now-1]=depth;}}
                        if(now+1<=200000){if(!visit[now+1]){queue[front++] = now+1;visit[now+1]=depth;}}
                        if(now*2<=200000){if(!visit[now*2]){queue[front++] = now*2;visit[now*2]=depth;}}
                }
        }

}
