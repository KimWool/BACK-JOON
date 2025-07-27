#include <stdio.h>

int main(void) {
	
	int T, X;
	scanf("%d %d", &T, &X);
	
	int N, temp = 0;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		int K;
		scanf("%d", &K);
		for(int j = 0; j < K; j++) {
			int time;
			scanf("%d", &time);
			if(time == X) {
				temp++;
			}
		}
	}
	
	if(temp == N) {
		printf("YES");
	} else {
		printf("NO");
	}
	
	return 0;
}