#include <stdio.h>
#include <math.h>

int compare(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int main(void){
	
	int n;
	scanf("%d", &n);
	
	int level[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &level[i]);
	}
	
	qsort(level, n, sizeof(int), compare);
	
	int cut = (int) round(n * 0.15);
	int sum = 0;
	for(int i = cut; i < n - cut; i++){
		sum += level[i];
	}
	
	int average = (n - 2 * cut) == 0 ? 0 : (int) round((double) sum / (n - 2 * cut));
	printf("%d", average); 
	
	return 0;
}