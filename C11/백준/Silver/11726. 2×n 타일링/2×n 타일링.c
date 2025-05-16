#include <stdio.h>

int main(void){
	
	long arr[1001];
	arr[1] = 1; arr[2] = 2;
	
	int n;
	scanf("%d", &n);
	for(int i = 3; i <= n; i++){
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	
	printf("%ld", arr[n]);
	
	return 0;
}