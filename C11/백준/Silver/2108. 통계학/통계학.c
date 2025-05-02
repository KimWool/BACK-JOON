#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int round(double x) {
    if (x >= 0){
		return (int)(x + 0.5);	
	}
    else {
		return (int)(x - 0.5);	
	}
}

int Mode(int N, int arr[]) {
    int i;
    int min = arr[0], max = arr[0];

    for (i = 1; i < N; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;
    int* count = (int*)calloc(range, sizeof(int));

    for (i = 0; i < N; i++) {
        count[arr[i] - min]++;
    }

    int maxCount = 0;
    for (i = 0; i < range; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
        }
    }

    int* modes = (int*)malloc(N * sizeof(int));
    int modeCount = 0;
    for (i = 0; i < range; i++) {
        if (count[i] == maxCount) {
            modes[modeCount++] = i + min;
        }
    }

    qsort(modes, modeCount, sizeof(int), compare);
    int result = (modeCount >= 2) ? modes[1] : modes[0];

    free(count);
    free(modes);

    return result;
}


int main(void){
	
	int N;
	scanf("%d", &N);
	
	int sum = 0;
	int arr[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	
	qsort(arr, N, sizeof(int), compare);
	
	printf("%d\n", round((double) sum / N));
	printf("%d\n", arr[N / 2]);
	printf("%d\n", Mode(N, arr));
	printf("%d", arr[N - 1] - arr[0]);
	
	return 0;
}