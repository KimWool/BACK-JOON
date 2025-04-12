#include <stdio.h>

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int num;
	int offset = 1000000; //범위 재조정용 변수 
	int count[2000001] = {0};
	
	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		count[num + offset]++;
	}
	
	for(int i = 0; i <= 2000000; i++){
		while(count[i]--){
			printf("%d\n", i - offset);
		}
	}
	
	return 0;
}