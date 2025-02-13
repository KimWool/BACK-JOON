#include <stdio.h>

int main(void){
	
	static long long result[1000001] = {0};
	for(int i = 1; i <= 1000000; i++){
		result[i] += result[i-1];
		for(int j = i; j <= 1000000; j += i){
			result[j] += i;
		}
	}
	
	int num;
	scanf("%d", &num);
	
	while(num--){
		int N;
		scanf("%d", &N);
		printf("%lld\n", result[N]);
	}
}