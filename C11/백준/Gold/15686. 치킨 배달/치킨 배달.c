#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct {
    int x, y;
} Point;

int N, M;
Point house[100];
Point chicken[13];
int houseCount = 0, chickenCount = 0;
int selected[13];
int answer = INF;

int absVal(int a) {
    return a < 0 ? -a : a;
}

int calcDistance() {
    int sum = 0;
    for (int i = 0; i < houseCount; i++) {
        int dist = INF;
        for (int j = 0; j < chickenCount; j++) {
            if (selected[j]) {
                int d = absVal(house[i].x - chicken[j].x) + absVal(house[i].y - chicken[j].y);
                if (d < dist) dist = d;
            }
        }
        sum += dist;
    }
    return sum;
}

void comb(int idx, int cnt) {
    if (cnt == M) {
        int sum = calcDistance();
        if (sum < answer) answer = sum;
        return;
    }
    if (idx == chickenCount) return;

    selected[idx] = 1;
    comb(idx + 1, cnt + 1);
    selected[idx] = 0;
    comb(idx + 1, cnt);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            scanf("%d", &val);
            if (val == 1) {
                house[houseCount].x = i;
                house[houseCount].y = j;
                houseCount++;
            } else if (val == 2) {
                chicken[chickenCount].x = i;
                chicken[chickenCount].y = j;
                chickenCount++;
            }
        }
    }

    comb(0, 0);
    printf("%d\n", answer);
    return 0;
}