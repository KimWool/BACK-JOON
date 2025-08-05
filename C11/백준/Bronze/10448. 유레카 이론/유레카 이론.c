#include <stdio.h>

int triangle[45];

void init_triangle() {
    for (int i = 1; i < 45; i++) {
        triangle[i] = i * (i + 1) / 2;
    }
}

int eureka(int K) {
    for (int i = 1; i < 45; i++) {
        for (int j = 1; j < 45; j++) {
            for (int k = 1; k < 45; k++) {
                if (triangle[i] + triangle[j] + triangle[k] == K) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int T, K;
    scanf("%d", &T);
    
    init_triangle();

    while (T--) {
        scanf("%d", &K);
        printf("%d\n", eureka(K));
    }

    return 0;
}