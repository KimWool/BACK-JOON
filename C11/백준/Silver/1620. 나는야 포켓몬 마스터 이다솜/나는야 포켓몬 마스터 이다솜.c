#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100001
#define NAME_LEN 21

typedef struct {
    char name[NAME_LEN];
    int index;
} Pokemon;

int compare(const void *a, const void *b) {
    return strcmp(((Pokemon *)a)->name, ((Pokemon *)b)->name);
}

int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

Pokemon pokemons[MAX];
char names_by_index[MAX][NAME_LEN];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", names_by_index[i + 1]);
        strcpy(pokemons[i].name, names_by_index[i + 1]);
        pokemons[i].index = i + 1;
    }

    qsort(pokemons, N, sizeof(Pokemon), compare);

    char input[NAME_LEN];
    for (int i = 0; i < M; i++) {
        scanf("%s", input);
        if (is_number(input)) {
            int idx = atoi(input);
            printf("%s\n", names_by_index[idx]);
        } else {
            Pokemon key;
            strcpy(key.name, input);
            Pokemon *found = bsearch(&key, pokemons, N, sizeof(Pokemon), compare);
            if (found != NULL) {
                printf("%d\n", found->index);
            }
        }
    }

    return 0;
}