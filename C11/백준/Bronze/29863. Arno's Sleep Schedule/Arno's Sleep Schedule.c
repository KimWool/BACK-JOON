#include <stdio.h>

int main(void){
	
	int start, end;
	scanf("%d %d", &start, &end);
	
	int sleep = (end - start + 24) % 24;
	printf("%d", sleep);
	
	return 0;
}