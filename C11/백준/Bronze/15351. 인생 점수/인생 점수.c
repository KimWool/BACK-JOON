#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        int score = 0;
        char enjoy[105];

        fgets(enjoy, sizeof(enjoy), stdin);

        for (int j = 0; j < strlen(enjoy); j++) {
            char ch = enjoy[j];
            if (ch >= 'A' && ch <= 'Z') {
                score += ch - 'A' + 1;
            }
        }

        if (score == 100) {
            printf("PERFECT LIFE\n");
        } else {
            printf("%d\n", score);
        }
    }

    return 0;
}