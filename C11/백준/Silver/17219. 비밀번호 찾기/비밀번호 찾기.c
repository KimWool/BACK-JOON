#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
#define MAX_LEN 21

typedef struct {
    char site[MAX_LEN];
    char password[MAX_LEN];
} Entry;

int compare(const void *a, const void *b) {
    return strcmp(((Entry *)a)->site, ((Entry *)b)->site);
}

int main() {
    int N, M;
    Entry entries[MAX];
    char query[MAX_LEN];

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s %s", entries[i].site, entries[i].password);
    }

    qsort(entries, N, sizeof(Entry), compare);

    for (int i = 0; i < M; i++) {
        scanf("%s", query);

        Entry key;
        strcpy(key.site, query);

        Entry *found = bsearch(&key, entries, N, sizeof(Entry), compare);
        if (found != NULL) {
            printf("%s\n", found->password);
        }
    }

    return 0;
}