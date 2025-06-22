#include <stdio.h>

int main(void){
	
	int BYear, BMonth, BDay;
	scanf("%d %d %d", &BYear, &BMonth, &BDay);
	
	int DYear, DMonth, DDay;
	scanf("%d %d %d", &DYear, &DMonth, &DDay);
	
	if(BMonth > DMonth || (BMonth == DMonth && BDay > DDay)){
		printf("%d\n", DYear - BYear - 1);
	} else {
		printf("%d\n", DYear - BYear);
	}
	
	printf("%d\n", DYear - BYear + 1);
	printf("%d", DYear - BYear);
	
	return 0;
}