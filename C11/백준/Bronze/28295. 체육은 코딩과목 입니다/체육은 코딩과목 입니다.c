#include <stdio.h>

int main(void){
	
	int command[10];
	int direction = 0;
	
	for(int i = 0; i < 10; i++){
		scanf("%d", &command[i]);
		switch(command[i]){
			case 1:
                direction += 1;
                break;
            case 2:
                direction += 2;
                break;
            case 3:
                direction += 3;
                break;
		}
	}
	
	direction = direction % 4;
	switch(direction){
		case 0:
            printf("N");
            break;
        case 1:
            printf("E");
            break;
        case 2:
            printf("S");
            break;
        case 3:
            printf("W");
            break;
	}
	
	return 0;
}