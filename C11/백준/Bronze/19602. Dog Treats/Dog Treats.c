#include <stdio.h>

int main(void) {
	
	int S, M, L;
	scanf("%d %d %d", &S, &M, &L);
	
	int happiness = S + 2 * M + 3 * L;
	if (happiness >= 10) {
		printf("happy");
	} else {
		printf("sad");
	}
	
	return 0;
}