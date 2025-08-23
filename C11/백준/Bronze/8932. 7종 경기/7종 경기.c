#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    double A, B, C;
    int flag;
} Match;

int main() {
    Match matches[7];
    matches[0] = (Match){9.23076, 26.7, 1.835, 1};
    matches[1] = (Match){1.84523, 75, 1.348, 0};
    matches[2] = (Match){56.0211, 1.5, 1.05, 0};
    matches[3] = (Match){4.99087, 42.5, 1.81, 1};
    matches[4] = (Match){0.188807, 210, 1.41, 0};
    matches[5] = (Match){15.9803, 3.8, 1.04, 0};
    matches[6] = (Match){0.11193, 254, 1.88, 1};

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int result = 0;
        int input[7];
        for (int j = 0; j < 7; j++) {
            scanf("%d", &input[j]);
        }

        for (int j = 0; j < 7; j++) {
            int score;
            int P = input[j];
            if (matches[j].flag) {
                score = (int)floor(matches[j].A * pow(matches[j].B - P, matches[j].C));
            } else {
                score = (int)floor(matches[j].A * pow(P - matches[j].B, matches[j].C));
            }
            result += score;
        }
        printf("%d\n", result);
    }

    return 0;
}