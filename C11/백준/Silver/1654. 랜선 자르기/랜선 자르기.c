#include <stdio.h>

int main(void){
	
	int K, N;
	scanf("%d %d", &K, &N);
	
	int length[K];
	long max = 0;
	for(int i = 0; i < K; i++){
		scanf("%d", &length[i]);
		if(length[i] > max){
			max = length[i];
		}
	}
	
	long left = 1;
	long right = max;
	long result = 0;
	
	while(left <= right){
		long mid = (left + right) / 2;
		long count = 0;
		for(int i = 0; i < K; i++){
			count += length[i] / mid;
		}
		
		if(count >= N){
			result = mid;
			left = mid + 1;
		} else{
			right = mid - 1;
		}
	}
	
	printf("%d", result);
	
	return 0;
}