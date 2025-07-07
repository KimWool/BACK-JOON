#include <stdio.h>
#include <math.h>

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int sum = 0;
	for(int i = 0; i < N; i++){
		int input;
		scanf("%d", &input);
		
		double base = input / 10;
		double exponent = input % 10;
		
		sum += (int) pow(base, exponent);
	}
	
	printf("%d", sum);
	
	return 0;
}