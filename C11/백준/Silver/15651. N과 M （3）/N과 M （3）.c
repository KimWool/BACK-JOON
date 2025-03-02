#include <stdio.h>

void backtrack(int n, int m, int depth, int arr[]){
	if(depth == m){
		for(int i = 0; i < m; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 1; i <= n; i++){
		arr[depth] = i;
		backtrack(n, m, depth + 1, arr);
	}
}

int main(void){
	
	int N, M;
	scanf("%d %d", &N, &M);
	
	int arr[10];
	
	backtrack(N, M, 0, arr);
	
	return 0;
}