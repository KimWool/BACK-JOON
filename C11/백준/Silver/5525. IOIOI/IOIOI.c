#include <stdio.h>

int main(void){
	
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M); //문자열 S의 길이
	
	char S[1000001];
	scanf("%s", S);
	
	int count = 0;
	int i = 0;
	int pattern = 0; //연결된 "OI"의 개수
	
	while(i < M - 1){
		if(S[i] == 'I' && S[i + 1] == 'O'){
			int j = i + 1;
			while(j + 1 < M && S[j] == 'O' && S[j + 1] == 'I'){
				pattern++;
				j += 2;
				
				if(pattern == N){
					count++;
					pattern--; //겹치는 패턴 고려 
				}
			}
			i = j; //다음 탐색 위치로 이동
			pattern = 0; 
		} else{
			i++;
		}
	}
	
	printf("%d", count);
	
	return 0;
}