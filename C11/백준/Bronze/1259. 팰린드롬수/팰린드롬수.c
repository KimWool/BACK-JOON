#include <stdio.h>
#include <string.h>

int main(void){
	
	char n[6];
	
	while(1){
		scanf("%s", n);
		if(n[0] == '0'){ break; }
		int len = strlen(n);
		int palindrome = 1;
		for(int i = 0; i < len / 2; i++){
			if(n[i] != n[len - i - 1]){
				palindrome = 0;
				break;
			}
		}
		if(palindrome){
			printf("yes\n");
		} else{
			printf("no\n");
		}
	}
	
	return 0;
}