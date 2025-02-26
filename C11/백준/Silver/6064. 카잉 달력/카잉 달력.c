#include <stdio.h>

int main(void){
	
	int T;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		int M, N, x, y;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		
		int k = -1;
		
		for(int j = x; j <= M * N; j += M){
			if(((j - 1) % N) + 1 == y){
				k = j;
				break;
			}
		}
		printf("%d\n", k);
	}
	
	return 0;
}