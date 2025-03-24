#include <stdio.h>

int arrays_equal(int arr1[], int arr2[], int size){
	for(int i = 0; i < size; i++){
		if(arr1[i] != arr2[i]){
			return 0; //두 배열이 일치하지 않음 
		}
	}
	return 1; //두 배열이 일치함 
}

int main(void){
	
	int syllable[8];
	for(int i = 0; i < 8; i++){
		scanf("%d", &syllable[i]);
	}
	
	int ascending[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	int descending[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	
	if(arrays_equal(syllable, ascending, 8)){
		printf("ascending");
	} else if(arrays_equal(syllable, descending, 8)){
		printf("descending");
	} else{
		printf("mixed");
	}
	
	return 0;
}