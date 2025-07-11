#include <stdio.h>

int main(void) {
	
	int N;
	scanf("%d", &N);
	
	int year = 2024;
	int month = 8;
	
	month += (N - 1) * 7;
	while(month > 12) {
		month -= 12;
		year++;
	}
	
	printf("%d %d", year, month);
	
	return 0;
}