#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);
    
    char A[50000], B[50000];
    scanf("%s %s", A, B);

    int result[100000];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int temp = (A[N - 1 - j] - '0') * (B[M - 1 - i] - '0');
            result[N + M - 1 - i - j] += temp;  
        }
    }

    for (int i = N + M - 1; i > 0; i--) {
        result[i - 1] += result[i] / 10;
        result[i] %= 10; 
    }

    int flag = 0;
    for (int i = 0; i < N + M; i++) {
        if (flag == 0) {
            if (result[i] != 0)
                flag = 1;
            else if (i == N + M - 1)
                printf("0");
        }
        if (flag != 0)
            printf("%d", result[i]);
    }
    
    return 0;
}