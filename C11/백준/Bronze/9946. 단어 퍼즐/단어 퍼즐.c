#include <stdio.h>
#include <string.h>

int isSame(char* original, char* received) {
    int originalFreq[26] = {0};
    int receivedFreq[26] = {0};

    for (int i = 0; original[i] != '\0'; i++) {
        originalFreq[original[i] - 'a']++;
    }

    for (int i = 0; received[i] != '\0'; i++) {
        receivedFreq[received[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (originalFreq[i] != receivedFreq[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char original[1001], received[1001];
    int caseNum = 1;

    while (1) {
        fgets(original, sizeof(original), stdin);
        fgets(received, sizeof(received), stdin);

        original[strcspn(original, "\n")] = '\0';
        received[strcspn(received, "\n")] = '\0';

        if (strcmp(original, "END") == 0 && strcmp(received, "END") == 0) {
            break;
        }

        if (isSame(original, received)) {
            printf("Case %d: same\n", caseNum);
        } else {
            printf("Case %d: different\n", caseNum);
        }

        caseNum++;
    }

    return 0;
}