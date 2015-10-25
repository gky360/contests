//poj3009.cpp
//PKU JudgeOnline
//poj3009 Curling 2.0

#include <cstdio>
#include <queue>
#define WMAX 20
#define HMAX 20
#define T 10	// ターン数の最大値
#define EDGE -1
#define VACANT 0
#define BLOCK 1
#define START 2
#define GOAL 3
using namespace std;


class board
{
	public:
	int t;	// 現在のターン数
	int data[WMAX + 2][HMAX + 2];	// 盤面。周囲に-1を置いて番兵とする。
	int x, y;	// 球の位置
	int thr();	// ゴールした時はそのターン数、それ以外は-1を返す
};

int W, H;
queue<board> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

int board::thr()
{
	board b;
	int d;
	int i, j;

	if(t == T){
		return -1;
	}
	t++;
	
	for(d = 0; d < 4; d++){
		i = x;
		j = y;
		if(data[i + dx[d]][j + dy[d]] == BLOCK){
			continue;
		}
		while(data[i + dx[d]][j + dy[d]] == VACANT){
			i += dx[d];
			j += dy[d];
		}
		switch(data[i + dx[d]][j + dy[d]]){	// START は最初に board に入力する段階で VACANT にしてしまう
		case EDGE:
			break;
		case BLOCK:
			b = *this;
			b.data[i + dx[d]][j + dy[d]] = VACANT;
			b.x = i;
			b.y = j;
			q.push(b);
			break;
		case GOAL:
			return t;
		}
	}

	return -1;
}


int main()
{
	board b;
	int i, j;

	while(scanf("%d %d", &W, &H) == 2 && W != 0){
		b.t = 0;
		for(i = 0; i < W + 2; i++){
			b.data[i][0] = EDGE;
			b.data[i][H + 1] = EDGE;
		}
		for(j = 0; j < H + 2; j++){
			b.data[0][j] = EDGE;
			b.data[W + 1][j] = EDGE;
		}
		for(j = 0; j < H; j++){
			for(i = 0; i < W; i++){
				scanf("%d", &b.data[i + 1][j + 1]);
				if(b.data[i + 1][j + 1] == START){	// START は最初に board に入力する段階で VACANT にしてしまう
					b.x = i + 1;
					b.y = j + 1;
					b.data[i + 1][j + 1] = VACANT;
				}
			}
		}
		while(!q.empty()){
			q.pop();
		}

		q.push(b);

		while(!q.empty()){
			ans = q.front().thr();
			if(ans > 0){
				break;
			}
			q.pop();
		}

		printf("%d\n", ans);
	}

	return 0;

}


