#include <stdio.h>

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int arr[N];
	
	int max = -1000001;
	int min = 1000001;
	
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
	}
	
	printf("%d %d", min, max);
	
	return 0;
}