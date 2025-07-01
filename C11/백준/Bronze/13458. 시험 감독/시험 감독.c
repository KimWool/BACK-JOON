#include <stdio.h>

int main(void){
	
	int N;
	scanf("%d", &N);
	
	int A[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	
	int B, C;
	scanf("%d %d", &B, &C);
	
	long min = 0;
	for(int i = 0; i < N; i++){
        if(A[i] <= B){
            min += 1;
        } else if(A[i] > B && (A[i] - B) % C == 0){
            min += 1 + (A[i] - B) / C;
        } else if(A[i] > B && (A[i] - B) % C != 0){
            min += 2 + (A[i] - B) / C;
        }
    }
    
    printf("%ld", min);
	
	return 0;
}