#include <stdio.h>

int main() {
    int A, B, C;
    
    scanf("%d %d %d", &A, &B, &C);

    if (A != B && A != C && B == C) {
        printf("A");
    } else if (B != A && B != C && A == C) {
        printf("B");
    } else if (C != A && C != B && A == B) {
        printf("C");
    } else {
        printf("*");
    }

    return 0;
}