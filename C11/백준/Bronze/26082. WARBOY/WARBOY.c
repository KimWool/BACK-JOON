#include <stdio.h>

int main(void){
	
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	
	int performance = B / A;
	printf("%d", performance * C * 3);
	
	return 0;
}