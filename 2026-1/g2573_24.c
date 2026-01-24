#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct {
    int x;
    int y;
} Point;

int N, M;
int map[300][300];      
int visited[300][300];   
int melt[300][300];      

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

Point queue[90001]; 
int front = 0, rear = 0;

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Point dequeue() {
    return queue[front++];
}

int is_empty() {
    return front == rear;
}

void bfs_check(int x, int y) {
    front = 0; rear = 0; 
    enqueue(x, y);
    visited[x][y] = 1;

    while (!is_empty()) {
        Point now = dequeue();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (map[nx][ny] > 0 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    enqueue(nx, ny);
                }
            }
        }
    }
}

int count_icebergs() {
    memset(visited, 0, sizeof(visited)); 
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] > 0 && !visited[i][j]) {
                bfs_check(i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int year = 0;

    while (1) {
        int lumps = count_icebergs();

        if (lumps >= 2) {
            printf("%d\n", year);
            break;
        }
        if (lumps == 0) { 
            printf("0\n");
            break;
        }
        memset(melt, 0, sizeof(melt)); 
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > 0) {
                    int sea_count = 0;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                            if (map[nx][ny] == 0) {
                                sea_count++;
                            }
                        }
                    }
                    melt[i][j] = sea_count;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > 0) {
                    map[i][j] -= melt[i][j];
                    if (map[i][j] < 0) map[i][j] = 0;
                }
            }
        }

        year++;
    }

    return 0;
}
