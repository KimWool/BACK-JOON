#include <stdio.h>
#include <string.h>

int main() {
    char word[101];

    scanf("%s", word);

    int number = 0;

    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            number++;
        }
    }

    printf("%d", number);

    return 0;
}