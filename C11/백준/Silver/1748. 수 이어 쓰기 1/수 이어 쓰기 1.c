#include <stdio.h>
#include <math.h>

int main(void){
	
	int N, max;
	double digits = 0;
	
	scanf("%d", &N);
	
	for(int i = 9; i >= 0; i--){
		if(N - pow(10, i) >= 0){
			max = i;
			digits = (i + 1) * (N - pow(10, i) + 1);
			break;
		}
	}
	
	for(int j = max; j > 0; j--){
		digits += j * (pow(10, j - 1) * 9);
	}
	
	printf("%ld", (long) digits);
	
	return 0;
}