#include <stdio.h>

#define MAX 1000

int main(void){
	
	int number = 1;
	char input[MAX];
	
	while(fgets(input, MAX, stdin)){
		if(input[0] == '0'){
			break;
		}
		printf("Case %d: Sorting... done!\n", number);
		number++;
	}
	
	return 0;
}