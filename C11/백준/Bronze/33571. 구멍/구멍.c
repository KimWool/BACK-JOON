#include <stdio.h>
#include <string.h>

int main() {
    int hole_count[256] = {0};

    hole_count['A'] = 1; hole_count['a'] = 1;
    hole_count['B'] = 2; hole_count['b'] = 1;
    hole_count['D'] = 1; hole_count['d'] = 1;
    hole_count['e'] = 1; hole_count['g'] = 1;
    hole_count['O'] = 1; hole_count['o'] = 1;
    hole_count['P'] = 1; hole_count['p'] = 1;
    hole_count['Q'] = 1; hole_count['q'] = 1;
    hole_count['R'] = 1; hole_count['@'] = 1;

    char S[1001];
    fgets(S, sizeof(S), stdin);
    
    int holes = 0;

    for (int i = 0; i < strlen(S); i++) {
        holes += hole_count[(unsigned char)S[i]];  // 해당 문자의 구멍 개수 추가
    }

    printf("%d", holes);

    return 0;
}