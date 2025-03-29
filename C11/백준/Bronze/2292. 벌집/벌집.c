#include <stdio.h>

int main(void){
	
	int N;
	int term = 1;
	int cycle = 1;
	
	scanf("%d", &N);
	while(term < N){
		term += 6 * cycle;
		cycle++;
	}
	
	printf("%d", cycle);
	
	return 0;
}