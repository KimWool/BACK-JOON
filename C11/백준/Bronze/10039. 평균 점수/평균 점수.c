#include <stdio.h>

int main(void){
	
	int sum = 0;
	
	int score[5];
	for(int i = 0; i < 5; i++){
		scanf("%d", &score[i]);
		if(score[i] >= 40){
			sum += score[i];
		} else{
			sum += 40;
		}
	}
	
	printf("%d", sum / 5);
	
	return 0;
}