#include <stdio.h>

int dp[41][2];

int main(void){
	
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	
	for (int i = 2; i <= 40; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
    	int N;
    	scanf("%d", &N);
    	printf("%d %d\n", dp[N][0], dp[N][1]);
	}
	
	return 0;
}