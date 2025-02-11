#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	int A = *(const int *)a;
	int B = *(const int *)b;
	return A - B;
}

int main(void){
	
	int num;
	scanf("%d", &num);
	
	int nn[num];
	for(int i = 0; i < num; i++){
		scanf("%d", &nn[i]);
	}
	
	qsort(nn, num, sizeof(int), compare);
	
	int N = nn[0] * nn[num - 1];
	printf("%d", N);
}