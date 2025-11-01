#include <stdio.h>

#define MAX 1000001

int x[100000];
int count[MAX];
int score[MAX];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
        count[x[i]] = 1;
    }

    for (int i = 0; i < N; i++) {
        int a = x[i];
        for (int j = a * 2; j < MAX; j += a) {
            if (count[j]) {
                score[a]++;
                score[j]--;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", score[x[i]]);
    }

    return 0;
}