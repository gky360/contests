//poj1222.cpp
//PKU JudgdeOnline
//poj1222 Extended Lights Out

#include <cstdio>
#define W 6
#define H 5


int N;
int light[W][H];
int ans[W];

void turn(int x, int y){
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {-1, 0, 1, 0};
	int i;
	
	light[x][y] = (light[x][y] + 1) % 2;
	for(i = 0; i < 4; i++){
		if((0 <= x + dx[i]) && (x + dx[i] < W)
							&& (0 <= y + dy[i]) && (y + dy[i] < H)){
			light[x + dx[i]][y + dy[i]] = (light[x + dx[i]][y + dy[i]] + 1) % 2;
		}
	}
	return;
}

int main(){
	
	bool tf;
	int i, j, k;
	
	scanf("%d", &N);
	for(k = 1; k <= N; k++){
		for(j = 0; j < H; j++){
			for(i = 0; i < W; i++){
				scanf("%d", &light[i][j]);
			}
		}
		
		for(ans[0] = 0; ans[0] < (1 << H); ans[0]++){
			for(j = 0; j < H; j++){
				if((ans[0] & (1 << j)) > 0){
					turn(0, j);
				}
			}
			for(i = 1; i < W; i++){
				ans[i] = 0;
				for(j = 0; j < H; j++){
					if(light[i - 1][j] == 1){
						ans[i] += (1 << j);
						turn(i, j);
					}
				}
			}
			
			tf = true;
			for(j = 0; j < H; j++){
				if(light[W - 1][j] == 1){
					tf = false;
				}
			}
			if(tf){
				break;
			}
			
			for(j = 0; j < H; j++){
				for(i = 0; i < W; i++){
					if((ans[i] & (1 << j)) > 0){
						turn(i, j);
					}
				}
			}
		}
		
		printf("PUZZLE #%d\n", k);
		for(j = 0; j < H; j++){
			for(i = 0; i < W; i++){
				printf("%d%c", (ans[i] >> j) & 1, (i == W - 1) ? '\n' : ' ');
			}
		}
	}
	
	return 0;
	
}


