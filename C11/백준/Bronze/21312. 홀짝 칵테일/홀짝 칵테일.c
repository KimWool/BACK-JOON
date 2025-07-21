#include <stdio.h>

int max_val(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	
	int max = A * B * C;
	int result = 0;
	
	if (A % 2 == 1) result = max_val(result, A);
	if (B % 2 == 1) result = max_val(result, B);
	if (C % 2 == 1) result = max_val(result, C);
	
	if (A % 2 == 1 && B % 2 == 1) result = max_val(result, A * B);
	if (B % 2 == 1 && C % 2 == 1) result = max_val(result, B * C);
	if (C % 2 == 1 && A % 2 == 1) result = max_val(result, C * A);
	
	if (A % 2 == 1 && B % 2 == 1 && C % 2 == 1) result = max_val(result, A * B * C);
	
	if (result == 0) {
		printf("%d", max);
	} else {
		printf("%d", result);
	}
	
	return 0;
}