//poj2385.cpp
//PKU JudgeOnline
//poj2385 Apple Catching

#include <cstdio>
#include <algorithm>
#define WMAX 30
using namespace std;


int T;
int W;
int dp[2][WMAX + 1];
int ans;

int main(){
	
	int tree;
	int i, j;
	
	scanf("%d %d", &T, &W);
	
	for(j = 0; j < W; j++){
		dp[0][j] = 0;
	}
	for(i = 1; i <= T; i++){
		scanf("%d", &tree);
		tree--;
		dp[i % 2][0] = dp[(i - 1) % 2][0] + (tree == 0 ? 1 : 0);
		for(j = 1; j <= min(W, i); j++){
			dp[i % 2][j] = max(dp[(i - 1) % 2][j - 1], dp[(i - 1) % 2][j]) + (j % 2 == tree ? 1 : 0);
		}
	}
	
	ans = 0;
	for(j = 0; j <= W; j++){
		ans = max(ans, dp[T % 2][j]);
	}
	
	printf("%d\n", ans);
	
	return 0;
	
}

