#include <stdio.h>

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int num;
	int count[10001] = {0};
	
	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		count[num]++;
	}
	
	for(int i = 0; i < 10001; i++){
		while(count[i]--){
			printf("%d\n", i);
		}
	}
	
	return 0;
}