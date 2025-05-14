#include <stdio.h>

int main(void){
	
	long padovan[101];
	padovan[1] = 1; padovan[2] = 1; padovan[3] = 1;
	
	for (int i = 4; i <= 100; i++) {
        padovan[i] = padovan[i - 2] + padovan[i - 3];
    }
    
    int T;
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++){
    	int N;
    	scanf("%d", &N);
    	printf("%ld\n", padovan[N]);
	}
	
	return 0;
}