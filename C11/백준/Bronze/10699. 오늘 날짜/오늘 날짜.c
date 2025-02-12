#include <stdio.h>
#include <time.h>

int main(){
	
	time_t now = time(NULL);
	struct tm *local = localtime(&now);
	
	printf("%04d-%02d-%02d", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday);
	
	/* struct tm 구조체
	local -> tm_year는 1900년을 기준으로 한 경과 년 수
	local -> tm_mon은 0월을 기준으로 한 달 수 */
		
}