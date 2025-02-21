#include <stdio.h>

int max_value(int a, int b){
	if(a > b){
		return a;
	} else{
		return b;
	}
}

void swap(int N, char board[][N+1], int i1, int j1, int i2, int j2) {
    char temp = board[i1][j1];
    board[i1][j1] = board[i2][j2];
    board[i2][j2] = temp;
}

int Count(int N, char board[][N+1]) {
    int maxCount = 0;

    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = 1; j < N; j++) {
            if (board[i][j] == board[i][j-1]) {
                count++;
            } else {
                maxCount = max_value(maxCount, count);
                count = 1;
            }
        }
        maxCount = max_value(maxCount, count);
    }

    for (int j = 0; j < N; j++) {
        int count = 1;
        for (int i = 1; i < N; i++) {
            if (board[i][j] == board[i-1][j]) {
                count++;
            } else {
                maxCount = max_value(maxCount, count);
                count = 1;
            }
        }
        maxCount = max_value(maxCount, count);
    }

    return maxCount;
}

int main(void) {
    int N = 0;
    scanf("%d", &N);
    
    char candy[N][N+1]; //null 종료 문자 표함
    for (int i = 0; i < N; i++) {
        scanf("%s", candy[i]);
    }
    
    int result = Count(N, candy);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j + 1 < N && candy[i][j] != candy[i][j + 1]) {
                swap(N, candy, i, j, i, j + 1);
                result = max_value(result, Count(N, candy));
                swap(N, candy, i, j, i, j + 1);
            }
            if (i + 1 < N && candy[i][j] != candy[i + 1][j]) {
                swap(N, candy, i, j, i + 1, j);
                result = max_value(result, Count(N, candy));
                swap(N, candy, i, j, i + 1, j);
            }
        }
    }
    
    printf("%d", result);
    
    return 0;
}