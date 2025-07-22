#include <stdio.h>

int main(void) {
	
	int N;
	scanf("%d", &N);
	
	int max = 0, min = 1000;
	
	for(int i = 0; i < N; i++) {
		int score;
		scanf("%d", &score);
		
		if(score > max) {
			max = score;
		}
		
		if(score < min) {
			min = score;
		}
	}
	
	printf("%d", max - min);
	
	return 0;
}