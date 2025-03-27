#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void){
	
	char S[101];
	fgets(S, sizeof(S), stdin);
	
	int alphabet[26];
	bool used[26];
	for(int i = 0; i < 26; i++){
		alphabet[i] = -1;
		used[i] = false;
	}
	
	for(int i = 0; i < strlen(S); i++){
		for(int j = 97; j <= 122; j++){
			if((S[i] == (char) j) && (!used[j - 97])){
				alphabet[j - 97] = i;
				used[j - 97] = true;
			}
		}
	}
	
	for(int i = 0; i < 26; i++){
		printf("%d ", alphabet[i]);
	}
	
	return 0;
}