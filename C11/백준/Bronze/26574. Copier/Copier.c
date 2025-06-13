#include <stdio.h>

int main(void){
	
	int number;
	scanf("%d", &number);
	
	for(int i = 0; i < number; i++){
		int n;
		scanf("%d", &n);
		printf("%d %d\n", n, n);
	}
	
	return 0;
}