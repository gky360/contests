//poj3050.cpp
//PKU JudgeOnline
//poj3050 Hopscotch

#include <cstdio>
#include <cmath>
#include <set>
using namespace std;


int loc[5][5];
set<int> s;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int ans;

void dfs(int x, int y, int num, int rank){
	int i;
	
	num += loc[x][y] * pow(10, rank);
	if(rank == 0){
		s.insert(num);
		return;
	}
	rank--;
	for(i = 0; i < 4; i++){
		if(0 <= x + dx[i] && x + dx[i] < 5 && 0 <= y + dy[i] && y + dy[i] < 5){
			dfs(x + dx[i], y + dy[i], num, rank);
		}
	}
	return;
}

int main(){
	
	int i, j;
	
	for(j = 0; j < 5; j++){
		for(i = 0; i < 5; i++){
			scanf("%d", &loc[i][j]);
		}
	}
	
	for(j = 0; j < 5; j++){
		for(i = 0; i < 5; i++){
			dfs(i, j, 0, 5);
		}
	}
	
	ans = s.size();
	printf("%d\n", ans);
	
	return 0;
	
}

