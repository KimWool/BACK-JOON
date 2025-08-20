#include <stdio.h>
#include <math.h>

int main() {
    int towerHeight;
    scanf("%d", &towerHeight);

    long long result = 1LL << towerHeight;
    printf("%lld\n", result);
    
    return 0;
}