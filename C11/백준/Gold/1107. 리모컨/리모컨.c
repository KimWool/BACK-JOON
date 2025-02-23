#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int min(int a, int b) {
    return a < b ? a : b;
}

bool validChannel(int N, int M, int button[]) {
    char buffer[10];
    sprintf(buffer, "%d", N);
    for (int i = 0; i < strlen(buffer); i++) {
        int digit = buffer[i] - '0';
        for (int j = 0; j < M; j++) {
            if (digit == button[j]) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    
    int button[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &button[i]);
    }
    
    int minClicks = abs(100 - N);
    
    for (int i = 0; i < 1000001; i++) {
        if (validChannel(i, M, button)) {
            char buffer[10];
            sprintf(buffer, "%d", i);
            int clicks = strlen(buffer) + abs(N - i);
            minClicks = min(minClicks, clicks);
        }
    }
    
    printf("%d", minClicks);
    
    return 0;
}