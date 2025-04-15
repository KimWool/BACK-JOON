#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
} Point;

int compare(const void *a, const void *b){
	Point *p1 = (Point *)a;
	Point *p2 = (Point *)b;
	if(p1->x == p2->x){
		return p1->y - p2->y;
	}
	return p1->x - p2->x;
}

int main(void){
	
	int N;
	scanf("%d", &N);
	
	Point points[N];
	
	for(int i = 0; i < N; i++){
		scanf("%d %d", &points[i].x, &points[i].y);
	}
	
	qsort(points, N, sizeof(Point), compare);
	
	for(int i = 0; i < N; i++){
		printf("%d %d\n", points[i].x, points[i].y);
	}
	
	return 0;
}