#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int binarySearch(int arr[], int size, int target){
	int left = 0;
	int right = size - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == target) {
			return 1;	
		} else if(arr[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
    }
    return 0;
}

int main(void){
	int N;
	scanf("%d", &N);

	int* A = (int*)malloc(sizeof(int) * N);
	for(int i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	
	qsort(A, N, sizeof(int), compare);

	int M;
	scanf("%d", &M);
	
	for(int i = 0; i < M; i++){
		int x;
		scanf("%d", &x);
		printf("%d\n", binarySearch(A, N, x));
	}

	free(A);
	
	return 0;
}