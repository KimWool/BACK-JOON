#include <stdio.h>

#define MAX 301

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	
	int stairs;
	scanf("%d", &stairs);
	
	int dp[MAX] = {0};
	int sum[MAX] = {0};
	
	for(int i = 1; i <= stairs; i++){
		scanf("%d", &sum[i]);
	}
	
	dp[1] = sum[1];
	if (stairs >= 2){
        dp[2] = sum[1] + sum[2];
    }
    if (stairs >= 3){
        for(int i = 3; i <= stairs; i++){
            dp[i] = max(dp[i - 2] + sum[i], dp[i - 3] + sum[i - 1] + sum[i]);
        }
    }
    
    printf("%d", dp[stairs]);
	
	return 0;
}