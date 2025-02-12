#include <stdio.h>

int main(){
	
	int N = 0;
	scanf("%d", &N);
	
	long result = 0;
	
	for(int i = 1; i <= N; i++){
		result += (long) i * (N / i);
	}
	
	printf("%ld", result);
		
}