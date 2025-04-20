#include <stdio.h>

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int dp[N + 1];
	for(int i = 1; i <= N; i++){
		dp[i] = 5000;
	}
	dp[0] = 0;
	
	for(int i = 1; i <= N; i++){
		if(i >= 3 && dp[i - 3] != 5000){
			dp[i] = min(dp[i], dp[i - 3] + 1);
		}
		if(i >= 5 && dp[i - 5] != 5000){
			dp[i] = min(dp[i], dp[i - 5] + 1);
		}
	}
	
	if(dp[N] == 5000){
		printf("%d", -1);
	} else{
		printf("%d", dp[N]);
	}
	
	return 0;
}