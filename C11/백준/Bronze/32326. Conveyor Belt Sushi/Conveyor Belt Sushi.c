#include <stdio.h>

int main(void){
	
	int plates[3];
	for(int i = 0; i < 3; i++){
		scanf("%d", &plates[i]);
	}
	
	int result = 0;
	int costs[3] = {3, 4, 5};
	for(int i = 0; i < 3; i++){
		result += plates[i] * costs[i];
	}
	
	printf("%d", result);
	
	return 0;
}