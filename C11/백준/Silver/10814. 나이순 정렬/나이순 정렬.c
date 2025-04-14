#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int age;
	char name[101]; //길이가 100보다 작거나 같은 문자열
} User;

int compare(const void *a, const void *b){
	User *u1 = (User *)a;
	User *u2 = (User *)b;
	return u1->age - u2->age;
}

int main(void){
	
	int N;
	scanf("%d", &N);
	
	User users[N];
	
	for(int i = 0; i < N; i++){
		scanf("%d %s", &users[i].age, users[i].name);
	}
	
	qsort(users, N, sizeof(User), compare);
	
	for(int i = 0; i < N; i++){
		printf("%d %s\n", users[i].age, users[i].name);
	}
	
	return 0;
}