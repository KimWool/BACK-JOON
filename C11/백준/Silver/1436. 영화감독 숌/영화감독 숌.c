#include <stdio.h>
#include <string.h>

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int num = 666;
	int count = 1;
	char str[30];
	
	while(count != N){
		num++;
		sprintf(str, "%d", num);
		if(strstr(str, "666") != NULL){
			count++;
		}
	}
	
	printf("%d", num);
	
	return 0;
}