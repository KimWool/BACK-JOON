#include <stdio.h>
#include <stdbool.h>

void backtrack(int n, int m, int depth, int arr[], bool visited[]){
	if(depth == m){
		for(int i = 0; i < m; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			for (int j = i - 1; j >= 1; j--) {
                visited[j] = true;
            }
			arr[depth] = i;
			backtrack(n, m, depth + 1, arr, visited);
			for (int j = i - 1; j >= 1; j--) {
                visited[j] = false;
            }
		}
	}
}

int main(void){
	
	int N, M;
	scanf("%d %d", &N, &M);
	
	bool visited[10] = { false };
	int arr[10];
	
	backtrack(N, M, 0, arr, visited);
	
	return 0;
}