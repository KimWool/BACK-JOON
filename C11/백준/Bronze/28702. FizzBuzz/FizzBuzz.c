#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isNumber(const char* s) {
    return strcmp(s, "Fizz") != 0 && strcmp(s, "Buzz") != 0 && strcmp(s, "FizzBuzz") != 0;
}

const char* FizzBuzz(int num) {
    if (num % 3 == 0 && num % 5 == 0) {
        return "FizzBuzz";
    } else if (num % 3 == 0) {
        return "Fizz";
    } else if (num % 5 == 0) {
        return "Buzz";
    } else {
        static char buf[10];
        sprintf(buf, "%d", num);
        return buf;
    }
}

int main(void){
	
	char first[10], second[10], third[10];
	scanf("%s %s %s", first, second, third);
	
	int num;
	
	if(isNumber(first)){
		num = atoi(first) + 3;
	} else if(isNumber(second)){
		num = atoi(second) + 2;
	} else{
		num = atoi(third) + 1;
	}
	
	printf("%s", FizzBuzz(num));
	
	return 0;
}