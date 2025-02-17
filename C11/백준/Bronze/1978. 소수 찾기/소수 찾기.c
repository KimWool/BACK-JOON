#include <stdio.h>
#include <stdbool.h>

int main(void){
	
	int cnt = 0;
	int num = 0;
	
	scanf("%d", &num);
	
	for(int i = 0; i < num; i++){
		int N = 0;
		bool isPrime = true;
		
		scanf("%d", &N);
		
		if(N < 2){
			isPrime = false;
		} else{
			for(int j = 2; j < N; j++){
				if(N % j == 0){
					isPrime = false;
					break;	
				}
			}
		}
		
		if(isPrime){
			cnt++;
		}	
	}
	
	printf("%d", cnt);
	
}