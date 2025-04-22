#include <stdio.h>
#include <string.h>

#define MAX 55

int main() {
	
	int T;
	scanf("%d", &T);
	getchar();
	
	char line[MAX];
	
	for(int i = 0; i < T; i++){
		fgets(line, MAX, stdin);
		
		char stack[MAX];
        int top = -1;
        int isBalanced = 1;

        for (int j = 0; line[j]; j++) {
            char ch = line[j];

            if (ch == '(') {
                stack[++top] = ch;
            } else if (ch == ')') {
                if (top == -1 || stack[top] != '(') {
                    isBalanced = 0;
                    break;
                }
                top--;
            }
        }

        if (top != -1) isBalanced = 0;

        printf("%s\n", isBalanced ? "YES" : "NO");
	}

    return 0;
}