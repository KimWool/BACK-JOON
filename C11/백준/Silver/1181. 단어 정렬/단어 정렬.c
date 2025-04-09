#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 20000 //단어의 최대 개수
#define MAX_LEN 51 //문자열의 최대 길이 

int compare(const void *a, const void *b){
	char *wordA = *(char **)a;
	char *wordB = *(char **)b;
	
	int lenA = strlen(wordA);
	int lenB = strlen(wordB);
	
	if(lenA != lenB){
		return lenA - lenB;
	} else{
		return strcmp(wordA, wordB);
	}
}

int main(void){
	
	int N;
	scanf("%d", &N);
	
	char *words[MAX_N];
	
	for(int i = 0; i < N; i++){
		words[i] = (char *)malloc(sizeof(char) * MAX_LEN);
		scanf("%s", words[i]);
	}
	
	qsort(words, N, sizeof(char *), compare);
	
	printf("%s\n", words[0]);
	for(int i = 1; i < N; i++){
		if(strcmp(words[i], words[i - 1]) != 0){
			printf("%s\n", words[i]);
		}
	}
	
	return 0;
}