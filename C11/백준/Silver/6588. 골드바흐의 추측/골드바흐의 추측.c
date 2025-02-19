#include <stdio.h>
#include <stdbool.h>

#define MAX 1000000

int main(void){
	
	int N;
	
	bool isPrime[MAX + 1];
	isPrime[0] = false;
	isPrime[1] = false;
	
	for(int i = 2; i < MAX + 1; i++){
		isPrime[i] = true;
	}
	
	for(int i = 2; i * i < MAX + 1; i++){
		if(isPrime[i]){
			for(int j = i * i; j < MAX + 1; j += i){
				isPrime[j] = false;
			}	
		}
	}
	
	while(scanf("%d", &N) == 1){
		if(N == 0){
			break;
		}
		
		bool found = false;
		
		for(int a = 3; a <= N / 2; a += 2){
			int b = N - a;
			if(isPrime[a] && isPrime[b]){
				printf("%d = %d + %d\n", N, a, b);
				found = true;
				break;
			}
		}
		if(!found){
			printf("Goldbach's conjecture is wrong.");
		}
	}
	
}