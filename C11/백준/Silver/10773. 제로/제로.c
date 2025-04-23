#include <stdio.h>

#define MAX 100000

int main(void){
	
	int K;
	scanf("%d", &K);
	
	int numbers[MAX];
	int top = 0;
	
	for(int i = 0; i < K; i++){
		int num;
		scanf("%d", &num);
		if(num != 0){
			numbers[top++] = num; //push 
		} else if(top > 0){
			top--; //pop
		}
	}
	
	int sum = 0;
	
	for(int i = 0; i < top; i++){
		sum += numbers[i];
	}
	
	printf("%d", sum);
	
	return 0;
}