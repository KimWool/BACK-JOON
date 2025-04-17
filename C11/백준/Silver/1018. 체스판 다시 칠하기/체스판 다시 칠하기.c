#include <stdio.h>

int min(int A, int B){
	return (A > B) ? B : A;
}

int countRepaint(char board[][50], int x, int y, char startColor){
	int count = 0;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			char expected = ((i + j) % 2 == 0) ? startColor : (startColor == 'W' ? 'B' : 'W');
			if(board[x + i][y + j] != expected){ count++; }
		}
	}
	return count;
}

int main(void){
	
	int M, N;
	scanf("%d %d", &M, &N);
	
	char board[50][50];
	for(int i = 0; i < M; i++){
		char line[51];
		scanf("%s", line);
		for(int j = 0; j < N; j++){
			board[i][j] = line[j];
		}
	}
	
	int result = 65;
	
	for(int x = 0; x <= M - 8; x++){
		for(int y = 0; y <= N - 8; y++){
			int repaintW = countRepaint(board, x, y, 'W');
			int repaintB = countRepaint(board, x, y, 'B');
			result = min(result, min(repaintW, repaintB));
		}
	}
	
	printf("%d", result);
	
	return 0;
}