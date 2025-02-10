#include <stdio.h>

int main(void){
	int A, B, C;
	
	scanf("%d %d %d", &A, &B, &C);
	
	int a1 = (A + B) % C;
	int a2 = ((A % C) + (B % C)) % C;
	int a3 = (A * B) % C;
	int a4 = ((A % C) * (B % C)) % C;
	
	printf("%d\n%d\n%d\n%d", a1, a2, a3, a4);
}