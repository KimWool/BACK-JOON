#include <stdio.h>
#include <stdlib.h>

int main() {
    int A, B, C, D;
    
    scanf("%d %d %d %d", &A, &B, &C, &D);
    
    int result = abs((A + D) - (B + C));
    printf("%d", result);

    return 0;
}