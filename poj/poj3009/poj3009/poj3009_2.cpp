//poj3009_2.cpp
//PKU JudgeOnline
//poj3009 Curling 2.0

#include <cstdio>
#include <algorithm>
#define WMAX 20
#define HMAX 20
#define T 10	// �^�[�����̍ő�l
#define EDGE -1
#define VACANT 0
#define BLOCK 1
#define START 2
#define GOAL 3
using namespace std;


int W, H;
int t;	// ���݂̃^�[����
int data[WMAX + 2][HMAX + 2];	// �ՖʁB���͂�-1��u���Ĕԕ��Ƃ���B
int x, y;	// ���̈ʒu
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

void dfs()
{
	int d;
	int i, j;

	t++;
	if(t >= ans){
		t--;
		return;
	}

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
		switch(data[i + dx[d]][j + dy[d]]){	// START �͍ŏ��� board �ɓ��͂���i�K�� VACANT �ɂ��Ă��܂�
		case EDGE:
			break;
		case BLOCK:
			data[i + dx[d]][j + dy[d]] = VACANT;
			swap(x, i);
			swap(y, j);
			dfs();
			data[x + dx[d]][y + dy[d]] = BLOCK;
			x = i;
			y = j;
			break;
		case GOAL:
			ans = min(ans, t);
			break;
		}
	}

	t--;
	return;
}

int main()
{
	int i, j;

	while(scanf("%d %d", &W, &H) == 2 && W != 0){
		t = 0;
		for(i = 0; i < W + 2; i++){
			data[i][0] = EDGE;
			data[i][H + 1] = EDGE;
		}
		for(j = 0; j < H + 2; j++){
			data[0][j] = EDGE;
			data[W + 1][j] = EDGE;
		}
		for(j = 0; j < H; j++){
			for(i = 0; i < W; i++){
				scanf("%d", &data[i + 1][j + 1]);
				if(data[i + 1][j + 1] == START){	// START �͍ŏ��� board �ɓ��͂���i�K�� VACANT �ɂ��Ă��܂�
					x = i + 1;
					y = j + 1;
					data[i + 1][j + 1] = VACANT;
				}
			}
		}
		ans = T + 1;

		dfs();

		printf("%d\n", ans == T + 1 ? -1 : ans);
	}

	return 0;

}


