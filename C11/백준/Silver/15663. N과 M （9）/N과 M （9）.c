#include <stdio.h>
#include <stdlib.h>

int N, M;
int arr[8], visited[8];

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int depth, int* currentSequence) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", currentSequence[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        if (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1]) {
            continue;
        }

        if (!visited[i]) {
            visited[i] = 1;
            currentSequence[depth] = arr[i];
            backtrack(depth + 1, currentSequence);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int arr_input[8];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr_input[i]);
    }

    for (int i = 0; i < N; i++) {
        arr[i] = arr_input[i];
    }

    qsort(arr, N, sizeof(int), compare);
    
    int currentSequence[8];
    backtrack(0, currentSequence);

    return 0;
}