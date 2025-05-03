#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void){
	
	int M;
	scanf("%d", &M);
	
	bool set[21] = {false};
	
	for(int i = 0; i < M; i++){
		char cmd[10];
		int x = 0;
		scanf("%s", cmd);
		
		if (strcmp(cmd, "add") == 0) {
            scanf("%d", &x);
            set[x] = true;
        } else if (strcmp(cmd, "remove") == 0) {
            scanf("%d", &x);
            set[x] = false;
        } else if (strcmp(cmd, "check") == 0) {
            scanf("%d", &x);
            printf("%d\n", set[x] ? 1 : 0);
        } else if (strcmp(cmd, "toggle") == 0) {
            scanf("%d", &x);
            set[x] = !set[x];
        } else if (strcmp(cmd, "all") == 0) {
            for (int j = 1; j <= 20; j++) {
                set[j] = true;
            }
        } else if (strcmp(cmd, "empty") == 0) {
            for (int j = 1; j <= 20; j++) {
                set[j] = false;
            }
        }
	}
	
	return 0;
}