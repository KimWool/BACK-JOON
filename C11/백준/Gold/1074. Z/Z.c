#include <stdio.h>

int r, c;

int Z(int size, int x, int y){
	if(size == 1){
		return 0;
	}
	
	int half = size / 2;
	int area = half * half;
	
	if(r < x + half && c < y + half){
		return Z(half, x, y);
	} else if(r < x + half && c >= y + half){
		return area + Z(half, x, y + half);
	} else if(r >= x + half && c < y + half){
		return 2 * area + Z(half, x + half, y);
	} else{
		return 3 * area + Z(half, x + half, y + half);
	}
}

int main(void){
	
	int N;
	scanf("%d %d %d", &N, &r, &c);
	
	int size = 2 << N;
	int result = Z(size, 0, 0);
	
	printf("%d", result);
	
	return 0;
}