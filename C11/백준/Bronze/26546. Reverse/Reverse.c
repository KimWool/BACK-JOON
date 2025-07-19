#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int a = 0; a < n; a++) {
        char s[101];
        int i, j;
        scanf("%s %d %d", s, &i, &j);

        int len = strlen(s);
        for (int b = 0; b < len; b++) {
            if (b < i || b >= j) {
                printf("%c", s[b]);
            }
        }
        printf("\n");
    }

    return 0;
}