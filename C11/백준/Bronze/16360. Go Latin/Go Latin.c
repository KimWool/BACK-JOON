#include <stdio.h>
#include <string.h>

void convertToPseudoLatin(char *word, char *result) {
    int len = strlen(word);

    if (len >= 2 && strcmp(&word[len - 2], "ne") == 0) {
        strncpy(result, word, len - 2);
        result[len - 2] = '\0';
        strcat(result, "anes");
    } else if (word[len - 1] == 'a') {
        strncpy(result, word, len - 1);
        result[len - 1] = '\0';
        strcat(result, "as");
    } else if (word[len - 1] == 'i' || word[len - 1] == 'y') {
        strncpy(result, word, len - 1);
        result[len - 1] = '\0';
        strcat(result, "ios");
    } else if (word[len - 1] == 'l') {
        strncpy(result, word, len - 1);
        result[len - 1] = '\0';
        strcat(result, "les");
    } else if (word[len - 1] == 'n') {
        strncpy(result, word, len - 1);
        result[len - 1] = '\0';
        strcat(result, "anes");
    } else if (word[len - 1] == 'o') {
        strncpy(result, word, len - 1);
        result[len - 1] = '\0';
        strcat(result, "os");
    } else if (word[len - 1] == 'r') {
        strncpy(result, word, len - 1);
        result[len - 1] = '\0';
        strcat(result, "res");
    } else if (word[len - 1] == 't') {
        strncpy(result, word, len - 1);
        result[len - 1] = '\0';
        strcat(result, "tas");
    } else if (word[len - 1] == 'u') {
        strncpy(result, word, len - 1);
        result[len - 1] = '\0';
        strcat(result, "us");
    } else if (word[len - 1] == 'v') {
        strncpy(result, word, len - 1);
        result[len - 1] = '\0';
        strcat(result, "ves");
    } else if (word[len - 1] == 'w') {
        strncpy(result, word, len - 1);
        result[len - 1] = '\0';
        strcat(result, "was");
    } else {
        strcpy(result, word);
        strcat(result, "us");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char word[35];
    char result[100];

    for (int i = 0; i < n; i++) {
        scanf("%s", word);
        convertToPseudoLatin(word, result);
        printf("%s\n", result);
    }

    return 0;
}