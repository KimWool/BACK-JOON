#include <stdio.h>
#include <stdbool.h>

int map[51][51];
bool visited[51][51];
int M, N;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int y, int x) {
	visited[y][x] = true;
	
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if(!visited[ny][nx] && map[ny][nx] == 1) {
                dfs(ny, nx);
            }
        }
	}
}

int main(void) {
	
	int T;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++) {
		int K;
		scanf("%d %d %d", &M, &N, &K);
		
		for(int j = 0; j < 51; j++) {
			for(int k = 0; k < 51; k++) {
				map[j][k] = 0;
				visited[j][k] = false;
			}
		}
		
		for(int j = 0; j < K; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		
		int worms = 0;
		
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < M; k++) {
				if(map[j][k] == 1 && !visited[j][k]) {
					dfs(j, k);
					worms++;
				}
			}
		}
		
		printf("%d\n", worms);
	}
	
	return 0;
}