#include <stdio.h>

int main(void){
	
	int L;
	scanf("%d", &L);
	
	char string[L + 1];
	scanf("%s", string);
	
	long hash = 0;
	long pow = 1;
	int M = 1234567891;
	
	for(int i = 0; i < L; i++){
		int num = string[i] - 'a' + 1;
		hash = (hash + (pow * num) % M) % M;
		pow = (pow * 31) % M;
	}
	
	printf("%ld", hash);
	
	return 0;
}