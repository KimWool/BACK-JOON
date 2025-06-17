#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int meetings[MAX][2];

int compare(const void *a, const void *b) {
    int *m1 = (int *)a;
    int *m2 = (int *)b;

    if (m1[1] == m2[1]) {
        return m1[0] - m2[0];
    }
    return m1[1] - m2[1];
}

int main(void){
	
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%d %d", &meetings[i][0], &meetings[i][1]);
	}
	
	qsort(meetings, N, sizeof(meetings[0]), compare);
	
	int count = 0, endTime = 0;
    for (int i = 0; i < N; i++) {
        if (meetings[i][0] >= endTime) {
            endTime = meetings[i][1];
            count++;
        }
    }

    printf("%d", count);
	
	return 0;
}