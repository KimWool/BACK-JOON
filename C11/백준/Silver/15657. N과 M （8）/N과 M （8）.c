#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b){
	int A = *(const int *)a;
	int B = *(const int *)b;
	return A - B;
}

void backtrack(int n, int m, int depth, int array[], int arr[], bool visited[]){
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
			arr[depth] = array[i];
			backtrack(n, m, depth + 1, array, arr, visited);
			for (int j = i - 1; j >= 1; j--) {
                visited[j] = false;
            }
		}
	}
}

int main(void){
	
	int N, M;
	scanf("%d %d", &N, &M);
	
	int array[10] = {0};
	bool visited[10] = { false };
	for(int i = 1; i <= N; i++){
		scanf("%d", &array[i]);
	}
	
	qsort(array, N + 1, sizeof(int), compare);
	int arr[10];
	
	backtrack(N, M, 0, array, arr, visited);
	
	return 0;
}