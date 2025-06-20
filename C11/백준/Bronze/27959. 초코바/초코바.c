#include <stdio.h>

int main(void){
	
	int N, M;
	scanf("%d %d", &N, &M);
	
	int money = N * 100;
	if(money >= M){
		printf("Yes");
	} else{
		printf("No");
	}
	
	return 0;
}