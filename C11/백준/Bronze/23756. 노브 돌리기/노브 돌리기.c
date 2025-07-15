#include <stdio.h>
#include <math.h>

int min(int a, int b) {
	return a > b ? b : a;
}

int main(void) {
	
	int N, A;
	scanf("%d %d", &N, &A);
	
	int Angles[N];
	int sum = 0;
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &Angles[i]);
		int case1 = abs(Angles[i] - A);
		int case2 = 360 - case1;
		sum += min(case1, case2);
		A = Angles[i];
	}
	
	printf("%d", sum);
	
	return 0;
}