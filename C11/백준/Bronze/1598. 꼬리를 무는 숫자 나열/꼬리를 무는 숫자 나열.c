#include <stdio.h>
#include <stdlib.h>

int getRow(int num) {
    return (num - 1) / 4 + 1;
}

int getCol(int num) {
    return (num - 1) % 4 + 1;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int nRow = getRow(N);
    int nCol = getCol(N);
    int mRow = getRow(M);
    int mCol = getCol(M);

    int distance = abs(nRow - mRow) + abs(nCol - mCol);
    printf("%d\n", distance);

    return 0;
}