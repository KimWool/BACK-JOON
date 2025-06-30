#include <stdio.h>

int main(void){
	
	int n;
	scanf("%d", &n);
	
	int A = 100, B = 100;
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a > b){
			B -= a;
		} else if(a < b){
			A -= b;
		}
	}
	
	printf("%d\n%d", A, B);
	
	return 0;
}