#include <stdio.h>

int main(void){
	
	int N, K;
	scanf("%d %d", &N, &K);
	
	int arr[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	
	int count = 0;
	for(int i = N - 1; i >= 0; i--){
		count += (K / arr[i]);
		K %= arr[i];
	}
	
	printf("%d", count);
	
	return 0;
}