#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int P[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &P[i]);
	}
	
	qsort(P, N, sizeof(int), compare);
	
	int sum = 0;
	int time = 0;
	for(int i = 0; i < N; i++){
		time += P[i];
		sum += time;
	}
	
	printf("%d", sum);
	
	return 0;
}