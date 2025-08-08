#include <stdio.h>

int main(void) {
	
	int N;
	scanf("%d", &N);
	
	int sum = 0;
	for(int i = 0; i < N; i++) {
		int study;
		scanf("%d", &study);
		sum += study;
	}
	
	sum += 8 * (N - 1);
	
	int day = sum / 24;
	int hour = sum % 24;
	
	printf("%d %d", day, hour);
	
	return 0;
}