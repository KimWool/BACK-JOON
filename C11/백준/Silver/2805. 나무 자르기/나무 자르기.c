#include <stdio.h>

int getAnswer(int max, int length[], int N, int M){
	int low = 0;
	int high = max;
	int answer = 0;
	
	while(low <= high){
		int mid = (low + high) / 2;
		
		long sum = 0;
		for(int i = 0; i < N; i++){
			if(length[i] > mid){
				sum += length[i] - mid;
			}
		}
		
		if(sum >= M){
			answer = mid;
			low = mid + 1;
		} else{
			high = mid - 1;
		}
	}
	
	return answer;
}

int main(void){
	
	int N, M;
	scanf("%d %d", &N, &M);
	
	int max = 0;
	int length[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &length[i]);
		if(length[i] > max){
			max = length[i];
		}
	}
	
	int answer = getAnswer(max, length, N, M);
	
	printf("%d", answer);
}