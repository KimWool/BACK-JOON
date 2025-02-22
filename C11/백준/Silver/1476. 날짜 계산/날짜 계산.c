#include <stdio.h>

int main(void){
	
	int E = 0;
	int S = 0;
	int M = 0;
	
	scanf("%d %d %d", &E, &S, &M);
	
	int Earth = 1;
	int Sun = 1;
	int Moon = 1;
	
	int year = 1;
	
	while(1){
		if(Earth > 15){ Earth = 1; }
		if(Sun > 28){ Sun = 1; }
		if(Moon > 19){ Moon = 1; }
		if((Earth == E) && (Sun == S) && (Moon == M)){
			break;
		}
		Earth++;
		Sun++;
		Moon++;
		year++;
	}
	
	printf("%d", year);
	
	return 0;
}