#include <stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	
	int min = max((N - M * K), 0);
	int max = N - M * (K - 1) - 1;
	
	printf("%d %d", min, max);
	
	return 0;
}