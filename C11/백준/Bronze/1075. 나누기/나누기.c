#include <stdio.h>

int main(void) {
	
	int N, F;
	scanf("%d %d", &N, &F);
	
	int temp = (N / 100) * 100;
	int result = (temp % F == 0) ? temp : temp + (F - (temp % F));
	
	printf("%02d", result % 100);
	
	return 0;
}