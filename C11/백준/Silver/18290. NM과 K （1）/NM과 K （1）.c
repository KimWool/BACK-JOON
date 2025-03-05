#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 10
#define MAX_M 10

int N, M, K;
int MaxSum = INT_MIN;

int board[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M] = { false };

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int max(int a, int b){
	return (a > b) ? a : b;
}

bool isValid(int x, int y){
	if(visited[x][y]) return false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny]) return false;
    }
    return true;
}

void backtrack(int count, int sum, int startX, int startY){
	if(count == K){
		MaxSum = max(MaxSum, sum);
		return;
	}
	
	for (int i = startX; i < N; i++) {
        for (int j = (i == startX ? startY : 0); j < M; j++) {
            if (isValid(i, j)) {
                visited[i][j] = true;
                backtrack(count + 1, sum + board[i][j], i, j);
                visited[i][j] = false;
            }
        }
    }
}

int main(void){
	
	scanf("%d %d %d", &N, &M, &K);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &board[i][j]);
			visited[i][j] = false;
		}
	}
	
	backtrack(0, 0, 0, 0);
	printf("%d", MaxSum);
	
	return 0;
}