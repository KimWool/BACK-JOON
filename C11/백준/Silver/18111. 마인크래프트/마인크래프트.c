#include <stdio.h>
#include <limits.h>

int Max(int a, int b){
	return a > b ? a : b;
}

int Min(int a, int b){
	return a > b ? b : a;
}

int main(void){
	
	int N, M, B;
	scanf("%d %d %d", &N, &M, &B);
	
	int ground[500][500];
	int max = 0; int min = 256;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &ground[i][j]);
			max = Max(max, ground[i][j]);
			min = Min(min, ground[i][j]);
		}
	}
	
	int resultTime = INT_MAX;
	int resultHeight = 0;
	
	for(int i = min; i <= max; i++){
        int time = 0;
        int inventory = B;
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                int diff = ground[j][k] - i;
                if (diff > 0) {
                    time += diff * 2;
                    inventory += diff;
                } else if (diff < 0) {
                    time += (-diff);
                    inventory -= (-diff);
                }
            }
        }

        if (inventory >= 0){
            if (time < resultTime || (time == resultTime && i > resultHeight)){
                resultTime = time;
                resultHeight = i;
            }
        }
    }
    
    printf("%d %d", resultTime, resultHeight);
	
	return 0;
}