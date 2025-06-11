#include <stdio.h>

int main(void){
	
	long A, B;
	scanf("%d %d", &A, &B);
	
	long result = (A + B) * (A - B);
	printf("%d", result);
	
	return 0;
}