#include <stdio.h>
#include <stdbool.h>

int main(void){
	
	int M = 0;
	int N = 0;
	scanf("%d %d", &M, &N);
	
	bool prime[N + 1];
	prime[1] = false;
	for(int i = 2; i <= N; i++){
		prime[i] = true;
	}
	
	for(int i = 2; i * i <= N; i ++){
		if(!prime[i]) continue;
		for(int j = 2; i * j <= N; j++){
			prime[i * j] = false;
		}
	}
	
	for(int i = M; i <= N; i++){
		if(prime[i]){
			printf("%d\n", i);
		}
	}
	
}