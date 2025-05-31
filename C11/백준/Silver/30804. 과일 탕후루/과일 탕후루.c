#include <stdio.h>

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int fruits[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &fruits[i]);
	}
	
	int count[10] = {0};
	int left = 0, right = 0;
	int kind = 0;
	int maxLength = 0;
	
	while(right < N){
		if(count[fruits[right]] == 0) kind++;
		count[fruits[right]]++;
		right++;
		
		while(kind > 2){
			count[fruits[left]]--;
            if (count[fruits[left]] == 0) kind--;
            left++;
		}
		
		maxLength = max(maxLength, right - left);
	}
	
	printf("%d", maxLength);
	
	return 0;
}