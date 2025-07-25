#include <stdio.h>

int main(void) {
	
	int a, w, v;
	scanf("%d %d %d", &a, &w, &v);
	
	if (w / v >= a) {
		printf("1");
	} else {
		printf("0");
	}
	
	return 0;
}