#include <stdio.h>

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int M = 0;
	float avg = 0;
	
	int scores[N];
	float MScores[N];
	
	for(int i = 0; i < N; i++){
		scanf("%d", &scores[i]);
		if(scores[i] > M){
			M = scores[i];
		}
	}
	
	for(int i = 0; i < N; i++){
		MScores[i] = (float) scores[i] / M * 100;
		avg += MScores[i];
	}
	
	printf("%f", avg / N);
	
	return 0;
}