#include <stdio.h>

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int x[N];
	int y[N];
	int rank[N];
	for(int i = 0; i < N; i++){
		scanf("%d %d", &x[i], &y[i]);
		rank[i] = 1;
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(x[i] < x[j] && y[i] < y[j]){
				rank[i]++;
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		printf("%d ", rank[i]);
	}
	
	return 0;
}