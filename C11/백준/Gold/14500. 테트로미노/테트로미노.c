#include <stdio.h>
#include <stdbool.h>

#define MAX_N 500
#define MAX_M 500

int N, M;
int maxSum = 0;

int board[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void DFS(int x, int y, int depth, int sum){
	
	if(depth == 4){
		if (sum > maxSum){
			maxSum = sum;
		}
		return;
	}
	
	for(int i = 0; i < 4; i++){
		int newX = x + dx[i];
		int newY = y + dy[i];
		
		if (newX >= 0 && newY >= 0 && newX < N && newY < M && !visited[newX][newY]) {
            visited[newX][newY] = true;
            DFS(newX, newY, depth + 1, sum + board[newX][newY]);
            visited[newX][newY] = false;
        }
	}
	
}

void checkTshaper(int x, int y){
	int shapes[4][3][2] = {
        { {0, 1}, {0, -1}, {1, 0} },	//ㅜ
        { {0, 1}, {0, -1}, {-1, 0} },  //ㅗ
        { {1, 0}, {-1, 0}, {0, 1} },   //ㅏ
        { {1, 0}, {-1, 0}, {0, -1} }   //ㅓ
    };
    
    for (int i = 0; i < 4; i++) {
        int sum = board[x][y];
        bool valid = true;
        for (int j = 0; j < 3; j++) {
            int newX = x + shapes[i][j][0];
            int newY = y + shapes[i][j][1];

            if (newX < 0 || newY < 0 || newX >= N || newY >= M) {
                valid = false;
                break;
            }
            sum += board[newX][newY];
        }
        if (valid && sum > maxSum) {
            maxSum = sum;
        }
    }
}

int main(void){
	
	scanf("%d %d", &N, &M);
	
	board[N][M];
	visited[N][M];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &board[i][j]);
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			visited[i][j] = true;
			DFS(i, j, 1, board[i][j]);
			visited[i][j] = false;
			checkTshaper(i, j);
		}
	}
	
	printf("%d", maxSum);
	
	return 0;
}