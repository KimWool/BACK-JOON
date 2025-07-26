#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int count = 0;

        for (int x = 1; x <= a; x++) {
            for (int y = 1; y <= b; y++) {
                for (int z = 1; z <= c; z++) {
                    int r1 = x % y;
                    int r2 = y % z;
                    int r3 = z % x;

                    if (r1 == r2 && r2 == r3) {
                        count++;
                    }
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}