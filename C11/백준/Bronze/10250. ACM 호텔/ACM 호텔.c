#include <stdio.h>

int main(void){
	
	int T;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);
		
		int floor = (N - 1) % H + 1;
		int number = (N - 1) / H + 1;
		
		printf("%d%02d\n", floor, number);
	}
	
	return 0;
}