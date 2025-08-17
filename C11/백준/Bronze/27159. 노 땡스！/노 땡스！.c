#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int cards[100];
    for (int i = 0; i < N; i++) {
        scanf("%d", &cards[i]);
    }

    int score = 0;
    int groupStart = cards[0];

    for (int i = 1; i < N; i++) {
        if (cards[i] != cards[i - 1] + 1) {
            score += groupStart;
            groupStart = cards[i];
        }
    }

    score += groupStart;

    printf("%d", score);

    return 0;
}