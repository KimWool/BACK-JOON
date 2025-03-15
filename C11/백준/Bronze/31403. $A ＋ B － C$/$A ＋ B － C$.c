#include <stdio.h>

int main(void){
	
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	
	char sum[20];
	int result;
	
	sprintf(sum, "%d%d", A, B);
	sscanf(sum, "%d", &result);
	
	printf("%d\n%d", A + B - C, result - C);
	
	return 0;
}