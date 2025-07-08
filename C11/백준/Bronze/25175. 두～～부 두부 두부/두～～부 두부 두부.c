#include <stdio.h>

int main(void){
	
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	
	int distance = K - 3;
	int next = ((M - 1 + distance) % N + N) % N + 1;
	
	printf("%d", next);
	
	return 0;
}