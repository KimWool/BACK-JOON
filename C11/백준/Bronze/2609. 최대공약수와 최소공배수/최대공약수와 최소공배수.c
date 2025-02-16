#include <stdio.h>

int GCD(int a, int b){
	if(b == 0) return a;
	int r = a % b;
	return GCD(b, r);
}

int LCM(int a, int b){
	return a * b / GCD(a, b);
}

int main(void){
	
	int a, b = 0;
	scanf("%d %d", &a, &b);
	
	int gcd = GCD(a, b);
	int lcm = LCM(a, b);
	
	printf("%d\n%d\n", gcd, lcm);
	
}