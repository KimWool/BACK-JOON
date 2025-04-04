#include <stdio.h>

int main(void){
	
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);
	
	int day = (V - A) / (A - B);
	if((V - A) % (A - B) != 0){
		day++;
	}
	
	printf("%d", day + 1);
	
	return 0;
}