#include <stdio.h>

int main(void){
	
	int people[15][15];
	for(int i = 0; i < 15; i++){
		people[0][i] = i + 1;
	}
	
	for(int i = 1; i < 15; i++){
		for(int j = 0; j < 15; j++){
			if(j == 0){
				people[i][j] = 1;
			} else{
				people[i][j] = people[i][j - 1] + people[i - 1][j];
			}
		}
	}
	
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		int K, N;
		scanf("%d %d", &K, &N);
		printf("%d\n", people[K][N - 1]);
	}
	
	return 0;
}