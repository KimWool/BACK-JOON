#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int N;
    scanf("%d", &N);

    int maxDp[3], minDp[3];
    int tempMax[3], tempMin[3];

    for (int i = 0; i < 3; i++) {
        scanf("%d", &maxDp[i]);
        minDp[i] = maxDp[i];
    }

    for (int i = 1; i < N; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        tempMax[0] = MAX(maxDp[0], maxDp[1]) + a;
        tempMax[1] = MAX(MAX(maxDp[0], maxDp[1]), maxDp[2]) + b;
        tempMax[2] = MAX(maxDp[1], maxDp[2]) + c;

        tempMin[0] = MIN(minDp[0], minDp[1]) + a;
        tempMin[1] = MIN(MIN(minDp[0], minDp[1]), minDp[2]) + b;
        tempMin[2] = MIN(minDp[1], minDp[2]) + c;

        for (int j = 0; j < 3; j++) {
            maxDp[j] = tempMax[j];
            minDp[j] = tempMin[j];
        }
    }

    int maxAns = MAX(MAX(maxDp[0], maxDp[1]), maxDp[2]);
    int minAns = MIN(MIN(minDp[0], minDp[1]), minDp[2]);

    printf("%d %d\n", maxAns, minAns);
    return 0;
}