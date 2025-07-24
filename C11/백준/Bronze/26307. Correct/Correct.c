#include <stdio.h>

int main(void) {
	
	int Hour, Min;
	scanf("%d %d", &Hour, &Min);
	
	int result = (Hour - 9) * 60 + Min;
	printf("%d", result);
	
	return 0;
}