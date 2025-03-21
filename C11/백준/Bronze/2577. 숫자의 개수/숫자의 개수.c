#include <stdio.h>

int main(void){
	
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	
	int result = A * B * C;
	int counts[10] = {0};
	
	while (result != 0){
		int digit = result % 10;
		counts[digit]++;
		result = result / 10;
	}
	
	for (int i = 0; i < 10; i++){
		printf("%d\n", counts[i]);
	}
	
	return 0;
}