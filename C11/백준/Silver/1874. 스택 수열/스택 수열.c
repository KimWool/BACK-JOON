#include <stdio.h>
#include <string.h>

#define MAX 100001
#define OUTPUT_MAX 200001

int main(void){
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int stack[MAX];
    int top = -1;
    int num = 1;
    int possible = 1;

    char output[OUTPUT_MAX][3];
    int output_idx = 0;

    for(int i = 0; i < n; i++){
        int target = arr[i];

        while(num <= target){
            stack[++top] = num++;
            strcpy(output[output_idx++], "+\n");
        }

        if(stack[top] == target){
            top--;
            strcpy(output[output_idx++], "-\n");
        } else{
            possible = 0;
            break;
        }
    }

    if(possible){
        for(int i = 0; i < output_idx; i++){
            printf("%s", output[i]);
        }
    } else {
        printf("NO\n");
    }

    return 0;
}