#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int total = a + (b / 4) - (b / 7);
        printf("%d\n", total);
    }

    return 0;
}