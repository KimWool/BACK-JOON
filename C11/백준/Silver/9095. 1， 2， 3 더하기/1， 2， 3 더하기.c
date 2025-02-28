#include <stdio.h>

int main(void){
	
	int T;
	scanf("%d", &T);
	
	int sum[12];
	sum[1] = 1;
	sum[2] = 2;
	sum[3] = 4;
	
	for(int i = 4; i < 11; i++){
		sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
	}
	
	for(int i = 0; i < T; i++){
		int n;
		scanf("%d", &n);
		printf("%d\n", sum[n]);
	}
	
	return 0;
}