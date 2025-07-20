#include <stdio.h>

int main(void) {
	
	int T;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++) {
		int G, C, E;
		scanf("%d %d %d", &G, &C, &E);
		
		int kilometer = 0;
        
        switch(G) {
            case 1:
                kilometer = 1;
                break;
            case 2:
                kilometer = 3;
                break;
            case 3:
                kilometer = 5;
                break;
        }
		
		if (C >= E) {
			printf("%d\n", 0);
		} else {
			int diff = E - C;
			printf("%d\n", diff * kilometer);
		}
	}
	
	return 0;
}