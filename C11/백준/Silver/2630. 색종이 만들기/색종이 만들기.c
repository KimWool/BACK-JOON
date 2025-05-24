#include <stdio.h>
#include <stdbool.h>

int paper[128][128];

int white = 0;
int blue = 0;

bool check(int row, int column, int size){
	int color = paper[row][column];
	
	for(int i = row; i < row + size; i++){
		for(int j = column; j < column + size; j++){
			if(paper[i][j] != color){
				return false;
			}
		}
	}
	return true;
}

void divide(int row, int column, int size){
	if(check(row, column, size)){
		if(paper[row][column] == 0){
			white++;
		} else{
			blue++;
		}
		return;
	}
	int newSize = size / 2;
	divide(row, column, newSize);
    divide(row, column + newSize, newSize);
    divide(row + newSize, column, newSize);
    divide(row + newSize, column + newSize, newSize);
}

int main(void){
	
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &paper[i][j]);
		}
	}
	
	divide(0, 0, N);
	
	printf("%d\n%d", white, blue);
	
	return 0;
}