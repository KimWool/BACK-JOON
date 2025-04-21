#include <stdio.h>
#include <string.h>

#define MAX 105

int main() {
    char line[MAX];

    while (1) {
        fgets(line, MAX, stdin);

        if (strcmp(line, ".\n") == 0 || strcmp(line, ".") == 0) break;

        char stack[MAX];
        int top = -1;
        int isBalanced = 1;

        for (int i = 0; line[i]; i++) {
            char ch = line[i];

            if (ch == '(' || ch == '[') {
                stack[++top] = ch;
            } else if (ch == ')') {
                if (top == -1 || stack[top] != '(') {
                    isBalanced = 0;
                    break;
                }
                top--;
            } else if (ch == ']') {
                if (top == -1 || stack[top] != '[') {
                    isBalanced = 0;
                    break;
                }
                top--;
            }
        }

        if (top != -1) isBalanced = 0;

        printf("%s\n", isBalanced ? "yes" : "no");
    }

    return 0;
}