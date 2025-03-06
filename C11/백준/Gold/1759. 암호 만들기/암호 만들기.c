#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
    return (*(const char *)a) - (*(const char *)b);
}

void backtrack(int c, int l, int start, int depth, char *alphabet, char *password){
	if (depth == l){
        int vowel = 0;
        int consonant = 0;
        for (int i = 0; i < l; i++) {
            char ch = password[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowel++;
            } else {
                consonant++;
            }
        }
        if (vowel >= 1 && consonant >= 2) {
            printf("%s\n", password);
        }
        
		return;
    }
    
	for (int i = start; i < c; i++) {
        password[depth] = alphabet[i];
        backtrack(c, l, i + 1, depth + 1, alphabet, password);
    }
}

int main(void){
	
	int L, C;
	
	scanf("%d %d", &L, &C);
	
	char alphabet[C];
	for(int i = 0; i < C; i++){
		scanf(" %c", &alphabet[i]);
	}
	
	qsort(alphabet, C, sizeof(char), compare);
	
	char password[L + 1];
	memset(password, 0, sizeof(password));
	
	backtrack(C, L, 0, 0, alphabet, password);
	
	return 0;
}