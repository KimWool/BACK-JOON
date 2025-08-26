#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

    int n;
    scanf("%d", &n);

    char s[10010];
    int k, len;
    
    while (n--){
        scanf("%s", s);
        len = strlen(s);
        k = 0;
        
        while (k * k < len) k++;

        for (int i=0; i<k; i++){
            for (int j=0; j<k; j++){
                printf("%c", s[(k-1-i) + j*k]);
            }
        }
        printf("\n");
    }

    return 0;
}