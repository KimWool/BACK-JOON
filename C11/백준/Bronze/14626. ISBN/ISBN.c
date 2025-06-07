#include <stdio.h>
#include <ctype.h>

int main(void){
	
	char ISBN[14];
	scanf("%s", ISBN);
	
	int result = 0;
	int missingIndex = -1;
	
	for(int i = 0; i < 13; i++){
		char c = ISBN[i];
		if(isdigit(c)){
			int digit = c - '0';
			int weight = (i % 2 == 0) ? 1 : 3;
			result += digit * weight;
		} else{
			missingIndex = i;
		}
	}
	
	for(int i = 0; i <= 9; i++){
		int weight = (missingIndex % 2 == 0) ? 1 : 3;
		int total = result + i * weight;
		if(total % 10 == 0){
			printf("%d", i);
			return 0;
		}
	}
}