#include <stdio.h>

int N;
int *T, *P;
int maxProfit = 0;

int max(int a, int b){
	return (a > b) ? a : b;
}

void backtrack(int date, int profit){
	if(date == N + 1){
		maxProfit = max(maxProfit, profit);
		return;
	}
	if(date + T[date] <= N + 1){
		backtrack(date + T[date], profit + P[date]);
	}
	backtrack(date + 1, profit);
}

int main(void){
	
	scanf("%d", &N);
	
	T = (int*)malloc((N + 1) * sizeof(int));
    P = (int*)malloc((N + 1) * sizeof(int));
	for(int i = 1; i <= N; i++){
		scanf("%d %d", &T[i], &P[i]);
	}
	
	backtrack(1, 0);
	printf("%d", maxProfit);
	
	return 0;
}