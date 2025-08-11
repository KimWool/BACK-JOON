#include <stdio.h>

int main() {
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    int friendsCount[N + 1];
    for (int i = 1; i <= N; i++) {
        friendsCount[i] = 0;
    }
    
    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        
        friendsCount[A]++;
        friendsCount[B]++;
    }
    
    for (int i = 1; i <= N; i++) {
        printf("%d\n", friendsCount[i]);
    }
    
    return 0;
}