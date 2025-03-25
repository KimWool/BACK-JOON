#include <stdio.h>

int main(void){
	
	int dividend[10];
	int remainder[10];
	
	for(int i = 0; i < 10; i++){
		scanf("%d", &dividend[i]);
		remainder[i] = dividend[i] % 42;
	}
	
	int n = 1;
	int set[10];
	set[0] = remainder[0];
	
	for(int i = 1; i < 10; i++){
		int found = 0;
		for(int j = 0; j < n; j++){
			if(remainder[i] == set[j]){
				found = 1;
				break;
			}
		}
		if(!found){
			set[n] = remainder[i];
			n++;
		}
	}
	
	printf("%d", n);
	
	return 0;
}