#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100001

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char p[MAX];
        scanf("%s", p);

        int n;
        scanf("%d", &n);

        char arr_str[MAX * 4];
        scanf("%s", arr_str);

        int arr[MAX];
        int front = 0, rear = n - 1;
        int isReversed = 0, isError = 0;

        int idx = 0;
        char *ptr = strtok(arr_str, "[,]");
        while (ptr != NULL && idx < n) {
            arr[idx++] = atoi(ptr);
            ptr = strtok(NULL, "[,]");
        }

        for (int i = 0; i < strlen(p); i++) {
            if (p[i] == 'R') {
                isReversed = !isReversed;
            } else if (p[i] == 'D') {
                if (front > rear) {
                    isError = 1;
                    break;
                }
                if (!isReversed) front++;
                else rear--;
            }
        }

        if (isError) {
            printf("error\n");
        } else {
            printf("[");
            if (!isReversed) {
                for (int i = front; i <= rear; i++) {
                    printf("%d", arr[i]);
                    if (i < rear) printf(",");
                }
            } else {
                for (int i = rear; i >= front; i--) {
                    printf("%d", arr[i]);
                    if (i > front) printf(",");
                }
            }
            printf("]\n");
        }
    }

    return 0;
}