#include <stdio.h>

int main(void){
	
	int A = 0;
	int B = 0;
	scanf("%d %d", &A, &B);
	
	int sum = A + B;
    int min = A - B;
    int mul = A * B;
    int div = A / B;
    int mod = A % B;
	
	printf("%d\n", sum);
	printf("%d\n", min);
	printf("%d\n", mul);
	printf("%d\n", div);
	printf("%d", mod);
	
	return 0;
} 