#include <stdio.h>

int main(void){
	
	int N, M;
	scanf("%d %d", &N, &M);
	
	int arr[N + 1];
	for(int i = 1; i <= N; i++){
		scanf("%d", &arr[i]);
	}
	
	int prefixSum[N + 1];
	for(int i = 1; i <= N; i++){
		prefixSum[i] = prefixSum[i - 1] + arr[i];
	}
	
	for(int i = 0; i < M; i++){
		int start, end;
		scanf("%d %d", &start, &end);
		printf("%d\n", prefixSum[end] - prefixSum[start - 1]);
	}
	
	return 0;
}