#include <stdio.h>
#include <string.h>

#define MAX 1001

int main() {
    int N, M;
	char A[MAX], B[MAX];
    int result[MAX * 2] = {0};

    scanf("%d %d", &A, &B);
    
	scanf("%s", A);
    scanf("%s", B);

    int lenA = strlen(A);
    int lenB = strlen(B);

    for (int i = lenA - 1; i >= 0; i--) {
        for (int j = lenB - 1; j >= 0; j--) {
            int mul = (A[i] - '0') * (B[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + result[p2];

            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }

    int start = 0;
    while (start < lenA + lenB && result[start] == 0) start++;

    if (start == lenA + lenB) printf("0");
    else {
        for (int i = start; i < lenA + lenB; i++) {
            printf("%d", result[i]);
        }
    }

    return 0;
}