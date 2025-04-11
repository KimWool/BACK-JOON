#include <stdio.h>

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int count = 0;
	for(int i = 5; i <= N; i *= 5){
		count += N / i;
	}
	
	printf("%d", count);
	
	return 0;
}