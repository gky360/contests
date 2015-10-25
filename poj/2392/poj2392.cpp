//poj2392.cpp
//PKU JudgeOnline
//poj2392 Space Elevator

#include <cstdio>
#include <algorithm>
#define KMAX 400
#define AMAX 40000
using namespace std;


struct block{
	int h, a, c;
};

bool operator<(block b1, block b2){
	return b1.a < b2.a;
}

int K;
int A;
block blk[KMAX];
int dp[2][AMAX + 1];
int ans;

int main(){
	
	int i, j;
	
	scanf("%d", &K);
	A = 0;
	for(i = 0; i < K; i++){
		scanf("%d %d %d", &blk[i].h, &blk[i].a, &blk[i].c);
		A = max(A, blk[i].a);
	}
	sort(blk, blk + K);
	
	for(j = 1; j <= A; j++){
		dp[1][j] = -1;
	}
	dp[1][0] = 0;
	
	for(i = 0; i < K; i++){
		for(j = 0; j <= A; j++){
			if(dp[(i - 1 + 2) % 2][j] >= 0){
				dp[i % 2][j] = blk[i].c;
			}else if(j <= blk[i].a && j >= blk[i].h && dp[i % 2][j - blk[i].h] > 0){
				dp[i % 2][j] = dp[i % 2][j - blk[i].h] - 1;
			}else{
				dp[i % 2][j] = -1;
			}
		}
	}
	
	ans = 0;
	for(j = 1; j <= A; j++){
		if(dp[(K - 1) % 2][j] >= 0){
			ans = j;
		}
	}
	printf("%d\n", ans);
	
	return 0;
	
}


