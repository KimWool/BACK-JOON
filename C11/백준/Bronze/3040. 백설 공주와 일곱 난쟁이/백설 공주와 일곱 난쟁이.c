#include <stdio.h>
#include <stdbool.h>

int main(void) {
	
	int sum = 0;
	int numbers[9];
	bool flag[9];
	
	for(int i = 0; i < 9; i++) {
		scanf("%d", &numbers[i]);
		sum += numbers[i];
		flag[i] = true;
	}
	
	int difference = sum - 100;
	for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (numbers[j] == difference - numbers[i]) {
                flag[i] = false;
                flag[j] = false;
                break;
            }
        }
    }
    
    for(int i = 0; i < 9; i++) {
    	if(flag[i]) {
    		printf("%d\n", numbers[i]);
		}
	}
	
	return 0;
}