#include <stdio.h>
#include <string.h>

int main() {
    int K;
    scanf("%d", &K);

    while (K--) {
        int P, M;
        scanf("%d %d", &P, &M);

        int seats[501] = {0};
        int rejected = 0;

        for (int i = 0; i < P; i++) {
            int preferred;
            scanf("%d", &preferred);
            if (!seats[preferred]) {
                seats[preferred] = 1;
            } else {
                rejected++;
            }
        }

        printf("%d\n", rejected);
    }

    return 0;
}