#include <stdio.h>
#include <string.h>

int main() {
    char photo[15][15];
    char result[20] = "";

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            scanf(" %c", &photo[i][j]);

            if (photo[i][j] == 'w') {
                strcpy(result, "chunbae");
            } else if (photo[i][j] == 'b') {
                strcpy(result, "nabi");
            } else if (photo[i][j] == 'g') {
                strcpy(result, "yeongcheol");
            }
        }
    }

    printf("%s", result);
    return 0;
}