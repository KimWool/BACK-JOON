#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    
    char price[110];
    
    for (int i = 0; i < N; i++) {
        scanf("%s", price);
        printf("%lu\n", strlen(price));
    }

    return 0;
}