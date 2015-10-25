//poj1979.cpp
//PKU JudgeOnline
//poj1979 Red and Black

#include <cstdio>
#include <queue>
#define WMAX 20
#define HMAX 20
using namespace std;


int W, H;
char loc[WMAX + 2][HMAX + 2];
queue<int> que;
int adj_x[4] = {0, 1, 0, -1};
int adj_y[4] = {-1, 0, 1, 0};
int ans;

int main(){
	
	char c;
	int x, y;
	int i, j;
	
	while(true){
		scanf("%d %d", &W, &H);
		if(W == 0){
			break;
		}
		for(i = 0; i < W + 2; i++){
			loc[i][0] = '#';
			loc[i][H + 1] = '#';
		}
		for(j = 0; j < H + 2; j++){
			loc[0][j] = '#';
			loc[W + 1][j] = '#';
		}
		for(j = 1; j <= H; j++){
			scanf("%c", &c);
			for(i = 1; i <= W; i++){
				scanf("%c", &loc[i][j]);
				if(loc[i][j] == '@'){
					que.push(i + j * (W + 2));
				}
			}
		}
		
		ans = 1;
		while(!que.empty()){
			x = que.front() % (W + 2);
			y = que.front() / (W + 2);
			que.pop();
			for(i = 0; i < 4; i++){
				if(loc[x + adj_x[i]][y + adj_y[i]] == '.'){
					loc[x + adj_x[i]][y + adj_y[i]] = '#';
					ans++;
					que.push((x + adj_x[i]) + (y + adj_y[i]) * (W + 2));
				}
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
	
}

