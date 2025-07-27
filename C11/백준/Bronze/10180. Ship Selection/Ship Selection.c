#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, D;
        scanf("%d %d", &N, &D);

        int count = 0;

        for (int j = 0; j < N; j++) {
            int vi, fi, ci;
            scanf("%d %d %d", &vi, &fi, &ci);

            if ((long long)vi * fi >= (long long)D * ci) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}