#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	
	int A = *(int*)a;
	int B = *(int*)b;
	
	return A - B;
}

int main(void){
	
	int total = 0;
	int heights[9];
	for(int i = 0; i < 9; i++){
		scanf("%d", &heights[i]);
		total += heights[i];
	}
	
	int diff = total - 100;
	
	for(int i = 0; i < 9; i++){
		for(int j = i + 1; j < 9; j++){
			if(heights[i] + heights[j] == diff){
				heights[i] = heights[j] = 0;
				goto exit;
			}
		}
	}
	
	exit:
		qsort(heights, 9, sizeof(int), compare);
		
		for(int i = 2; i < 9; i++){
			printf("%d\n", heights[i]);
		}
		
		return 0;
}