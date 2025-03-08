#include <stdio.h>
#include <math.h>

int main(void){
	
	int numbers[5];
	double clarify = 0;
	
	for(int i = 0; i < 5; i++){
		scanf("%d", &numbers[i]);
		clarify += pow(numbers[i], 2);
	}
	
	printf("%d", (int) clarify % 10);
	
	return 0;
}