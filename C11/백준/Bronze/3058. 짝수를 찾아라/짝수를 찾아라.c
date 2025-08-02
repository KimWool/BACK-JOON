#include <stdio.h>
#include <limits.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int num;
        int sum = 0;
        int min = INT_MAX;

        for (int j = 0; j < 7; j++) {
            scanf("%d", &num);

            if (num % 2 == 0) {
                sum += num;
                if (num < min) {
                    min = num;
                }
            }
        }

        printf("%d %d\n", sum, min);
    }

    return 0;
}