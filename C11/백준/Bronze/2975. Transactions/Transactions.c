#include <stdio.h>

int main() {
    int balance, amount;
    char type;

    while (1) {
        scanf("%d %c %d", &balance, &type, &amount);
        if (balance == 0 && type == 'W' && amount == 0) {
            break;
        }

        if (type == 'W') {
            if (balance - amount < -200) {
                printf("Not allowed\n");
            } else {
                balance -= amount;
                printf("%d\n", balance);
            }
        } else if (type == 'D') {
            balance += amount;
            printf("%d\n", balance);
        }
    }

    return 0;
}