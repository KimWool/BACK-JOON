#include <stdio.h>
#include <string.h>

#define MAX 1000001

int main() {
    char str[MAX];
    char bomb[37];
    char result[MAX];
    int top = 0;

    scanf("%s", str);
    scanf("%s", bomb);

    int lenStr = strlen(str);
    int lenBomb = strlen(bomb);

    for (int i = 0; i < lenStr; i++) {
        result[top++] = str[i];
        if (top >= lenBomb) {
            int flag = 1;
            for (int j = 0; j < lenBomb; j++) {
                if (result[top - lenBomb + j] != bomb[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                top -= lenBomb;
            }
        }
    }

    if (top == 0) {
        printf("FRULA\n");
    } else {
        result[top] = '\0';
        printf("%s\n", result);
    }

    return 0;
}