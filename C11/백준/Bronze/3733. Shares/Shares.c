#include <stdio.h>

int main() {
    int N, S;

    while (scanf("%d %d", &N, &S) != EOF) {
        int people = N + 1;
        printf("%d\n", S / people);
    }

    return 0;
}
