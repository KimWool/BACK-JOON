#include <stdio.h>

int main(void) {
	
	char input;
	scanf("%c", &input);
	
	if (input == 'N' || input == 'n') {
		printf("Naver D2");
	} else {
		printf("Naver Whale");
	}
	
	return 0;
}