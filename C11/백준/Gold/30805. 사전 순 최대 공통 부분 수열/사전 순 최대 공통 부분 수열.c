#include <stdio.h>

int main() {
    int n, m;
    int A[1001], B[1001];
    int result[1001];
    int ai = 0, bi = 0, rlen = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &B[i]);

    while (ai < n && bi < m) {
        int maxVal = 0;
        for (int i = ai; i < n; i++) {
            for (int j = bi; j < m; j++) {
                if (A[i] == B[j] && A[i] > maxVal) {
                    maxVal = A[i];
                }
            }
        }

        if (maxVal == 0) break;

        while (ai < n && A[ai] != maxVal) ai++;
        while (bi < m && B[bi] != maxVal) bi++;

        result[rlen++] = maxVal;
        ai++;
        bi++;
    }

    printf("%d\n", rlen);
    for (int i = 0; i < rlen; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}