#include <stdio.h>
#include <string.h>

int main(void){
	
	int T;
	scanf("%d", &T);
	getchar();
	
	for(int i = 0; i < T; i++){
		int grade = 0;
		int total = 0;
		char errata[81];
		fgets(errata, sizeof(errata), stdin);
		for(int j = 0; j < strlen(errata); j++){
			if(errata[j] == 'O'){
				grade++;
				total += grade;
			} else if (errata[j] == 'X'){
				grade = 0;
			}
		}
		printf("%d\n", total);
	}
	
	return 0;
}