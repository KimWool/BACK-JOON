#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500000
#define NAME_LEN 21

char notListen[MAX][NAME_LEN];
char result[MAX][NAME_LEN];
int resultCount = 0;

int cmp(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
}

int binary_search(char arr[][NAME_LEN], int size, char* target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmpResult = strcmp(arr[mid], target);
        if (cmpResult == 0) return 1;
        else if (cmpResult < 0) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", notListen[i]);
    }

    qsort(notListen, N, NAME_LEN, cmp);

    for (int i = 0; i < M; i++) {
        char name[NAME_LEN];
        scanf("%s", name);
        if (binary_search(notListen, N, name)) {
            strcpy(result[resultCount++], name);
        }
    }

    qsort(result, resultCount, NAME_LEN, cmp);

    printf("%d\n", resultCount);
    for (int i = 0; i < resultCount; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}