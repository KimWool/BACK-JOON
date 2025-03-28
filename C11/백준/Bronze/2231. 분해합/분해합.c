#include <stdio.h>

int main(void){
	
	int N;
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i++){
		int sum = i;
		int temp = i;
		while(temp > 0){
			sum += temp % 10;
			temp /=10;
		}
		if(sum == N){
			printf("%d", i);
			return 0;
		}
	}
	
	printf("%d", 0);
	
	return 0;
}