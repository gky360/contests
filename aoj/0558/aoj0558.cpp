//aoj0558.cpp
//AIZU ONLINE JUDGE
//aoj0558 Cheese

#include <cstdio>
#include <queue>
#define HMAX 1000
#define WMAX 1000
#define NMAX 9
#define INF 100000000
using namespace std;


int H, W;
int N;
char loc[HMAX + 2][WMAX + 2];
int dist[HMAX + 2][WMAX + 2];
int factory[NMAX + 1];
queue<int> que;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int ans = 0;

int main(){
	
	char tmp;
	int x, y;
	int i, j, k;
	
	scanf("%d %d %d", &H, &W, &N);
	for(i = 0; i < H + 2; i++){
		loc[i][0] = 'X';
		loc[i][W + 1] = 'X';
	}
	for(j = 0; j < W + 2; j++){
		loc[0][j] = 'X';
		loc[H + 1][j] = 'X';
	}
	for(i = 1; i <= H; i++){
		scanf("%c", &tmp);
		for(j = 1; j <= W; j++){
			scanf("%c", &loc[i][j]);
			if(loc[i][j] == 'S'){
				factory[0] = i + j * (H + 2);
				loc[i][j] = '.';
			}else if(49 <= loc[i][j] && loc[i][j] <= 57){
				factory[(int)loc[i][j] - 48] = i + j * (H + 2);
				loc[i][j] = '.';
			}
		}
	}
	
	ans = 0;
	for(k = 0; k < N; k++){
		while(!que.empty()){
			que.pop();
		}
		for(i = 0; i < H + 2; i++){
			for(j = 0; j < W + 2; j++){
				dist[i][j] = INF;
			}
		}
		dist[factory[k] % (H + 2)][factory[k] / (H + 2)] = 0;
		que.push(factory[k]);
		while(!que.empty()){
			if(que.front() == factory[k + 1]){
				break;
			}
			x = que.front() % (H + 2);
			y = que.front() / (H + 2);
			que.pop();
			for(i = 0; i < 4; i++){
				if(loc[x + dx[i]][y + dy[i]] == '.' && dist[x + dx[i]][y + dy[i]] > dist[x][y] + 1){
					dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
					que.push((x + dx[i]) + (y + dy[i]) * (H + 2));
				}
			}
		}
		ans += dist[factory[k + 1] % (H + 2)][factory[k + 1] / (H + 2)];
	}
	
	printf("%d\n", ans);
	
	return 0;
	
}

