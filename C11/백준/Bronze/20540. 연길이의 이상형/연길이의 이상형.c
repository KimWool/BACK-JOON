#include <stdio.h>

int main(void){
	
	char mbti[5];
	scanf("%4s", mbti);
	
	char result[4];
	
	if (mbti[0] == 'E') {
        result[0] = 'I';
    } else {
        result[0] = 'E';
    }
    
    if (mbti[1] == 'S') {
        result[1] = 'N';
    } else {
        result[1] = 'S';
    }
    
    if (mbti[2] == 'T') {
        result[2] = 'F';
    } else {
        result[2] = 'T';
    }
    
    if (mbti[3] == 'J') {
        result[3] = 'P';
    } else {
        result[3] = 'J';
    }
    
    result[4] = '\0';
    
    printf("%s", result);
	
	return 0;
}