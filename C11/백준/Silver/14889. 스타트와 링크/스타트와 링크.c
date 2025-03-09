#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int N;
int **S;
bool *isStart;

int minStatus = INT_MAX;

int min(int a, int b){
	return (a < b) ? a : b;
}

void difference(){
	
	int startTeam = 0;
	int linkTeam = 0;
	
	for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isStart[i] && isStart[j]) {
                startTeam += S[i][j];
            } else if (!isStart[i] && !isStart[j]) {
                linkTeam += S[i][j];
            }
        }
    }
	
	int diff = abs(startTeam - linkTeam);
	minStatus = min(diff, minStatus);
}

void backtrack(int index, int count){
	if (count == N / 2) {
        difference();
        return;
    }
    for (int i = index; i < N; i++) {
        if (!isStart[i]) {
            isStart[i] = true;
            backtrack(i + 1, count + 1);
            isStart[i] = false;
        }
    }
}

int main(void){
	
	scanf("%d", &N);
	
	S = (int **)malloc(N * sizeof(int *));
	for(int i = 0; i < N; i++){
		S[i] = (int *)malloc(N * sizeof(int));
	}
	
	isStart = (bool *)malloc(N * sizeof(bool));
	
	for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &S[i][j]);
        }
    }
    
    backtrack(0, 0);
    printf("%d", minStatus);
	
	return 0;
}