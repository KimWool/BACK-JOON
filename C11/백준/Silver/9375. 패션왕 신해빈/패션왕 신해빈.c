#include <stdio.h>
#include <string.h>

#define MAX 30

typedef struct {
    char type[21];
    int count;
} ClothType;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        ClothType cloths[MAX];
        int kindCount = 0;

        for (int i = 0; i < n; i++) {
            char name[21], type[21];
            scanf("%s %s", name, type);
            int found = 0;
            for (int j = 0; j < kindCount; j++) {
                if (strcmp(cloths[j].type, type) == 0) {
                    cloths[j].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(cloths[kindCount].type, type);
                cloths[kindCount].count = 1;
                kindCount++;
            }
        }

        int result = 1;
        for (int i = 0; i < kindCount; i++) {
            result *= (cloths[i].count + 1);
        }
        result -= 1;

        printf("%d\n", result);
    }

    return 0;
}