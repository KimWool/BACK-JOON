#include <stdio.h>

int main(void){
	
	int N;
	scanf("%d", &N);
	
	char numbers[N + 1];
	scanf("%s", numbers);
	
	int sum = 0;
	
	for(int i = 0; i < N; i++){
		int number = numbers[i] - '0';
		sum += number;
	}
	
	printf("%d", sum);
	
	return 0;
}