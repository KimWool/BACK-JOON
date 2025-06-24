#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    while (T--) {
        char input[101];
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = 0;

        int length = strlen(input);

        bool first_visited[101] = { false };
        char first[101] = { 0 };
        int first_index = 0, first_pos = 0;
        while (!first_visited[first_index]) {
            first_visited[first_index] = true;
            first[first_pos++] = input[first_index];
            first_index = (first_index + 2) % length;
        }
        first[first_pos] = '\0';

        bool second_visited[101] = { false };
        char second[101] = { 0 };
        int second_index = 1 % length, second_pos = 0;
        while (!second_visited[second_index]) {
            second_visited[second_index] = true;
            second[second_pos++] = input[second_index];
            second_index = (second_index + 2) % length;
        }
        second[second_pos] = '\0';

        printf("%s\n%s\n", first, second);
    }

    return 0;
}