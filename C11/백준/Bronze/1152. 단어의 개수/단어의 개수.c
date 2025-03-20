#include <stdio.h>
#include <string.h>

int main(void){
	
	char sentence[1000001];
	fgets(sentence, sizeof(sentence), stdin); //문장 입력받기
	sentence[strcspn(sentence, "\n")] = '\0'; //개행 문자 제거 
	
	char *words = strtok(sentence, " ");
	int blanks = 0;
	
	if (words == NULL){
		printf("%d", 0);
		return 0;
	}
	
	while (words != NULL){
		blanks++;
		words = strtok(NULL, " ");
	}
	
	printf("%d", blanks);
	
	return 0;
}