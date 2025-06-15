#include <stdio.h>
#include <stdlib.h>

int compare(const void *A, const void *B){
	if(*(int*) A > *(int*) B){
		return 1;
	} else if(*(int*) A < *(int*) B){
		return -1;
	} else{
		return 0;
	}
}

int main(void){
	
	int numbers[3];
	for(int i = 0; i < 3; i++){
		scanf("%d", &numbers[i]);
	}
	
	qsort(numbers, sizeof(numbers)/sizeof(int), sizeof(int), compare);
	
	printf("%d", numbers[1]);
	
	return 0;
}