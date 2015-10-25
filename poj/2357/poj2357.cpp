//poj2357.cpp
//PKU JudgeOnline
//poj2357 Labyrinth

#include <cstdio>
#include <queue>
#define NMAX 33
using namespace std;


int N;
char p[NMAX + 2][NMAX + 2];
queue<int> qx;
queue<int> qy;
int vx[4] = {1, 0, -1, 0};
int vy[4] = {0, 1, 0, -1};
int ans;

int main(){
	
	int x, y;
	int i, j;
	
	scanf("%d", &N);
	for(j = 1; j <= N; j++){
		scanf("%s", &p[j][1]);
	}
	for(i = 0; i <= N + 1; i++){
		p[i][0] = '#';
		p[i][N + 1] = '#';
	}
	for(j = 0; j <= N; j++){
		p[0][j] = '#';
		p[N + 1][j] = '#';
	}
	
	ans = 0;
	qx.push(1);
	qy.push(1);
	qx.push(N);
	qy.push(N);
	while(!qx.empty()){
		x = qx.front(); qx.pop();
		y = qy.front(); qy.pop();
		if(p[x][y] == '#'){
			ans++;
		}else if(p[x][y] == '.'){
			p[x][y] = 'o';
			for(i = 0; i < 4; i++){
				qx.push(x + vx[i]);
				qy.push(y + vy[i]);
			}
		}
	}
	
	ans = (ans - 4) * 9;
	printf("%d\n", ans);
	
	return 0;
	
}

