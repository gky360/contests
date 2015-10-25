//poj3280.cpp
//PKU JudgeOnline
//poj3280 Cheapest Palindrome

#include <cstdio>
#include <algorithm>
#define NMAX 26
#define MMAX 2000
#define B 97	//BIAS
using namespace std;


int N;
int M;
char s[MMAX + 1];
int cost[NMAX];
int dp[MMAX][MMAX];
int ans;

int main(){
	
	char tmpc, c;
	int tmpCost0, tmpCost1;
	int i, j, k;
	
	scanf("%d %d", &N, &M);
	scanf("%s", s);
	for(i = 0; i < N; i++){
		scanf("%c%c %d %d", &tmpc, &c, &tmpCost0, &tmpCost1);
		cost[c - B] = min(tmpCost0, tmpCost1);
	}
	
	dp[0][0] = 0;
	for(i = 1; i < M; i++){
		dp[i][i] = 0;
		dp[i][i - 1] = 0;
	}
	
	for(k = 1; k < M; k++){
		for(i = 0; i + k < M; i++){
			j = i + k;
			if(s[i] == s[j]){
				dp[i][j] = dp[i + 1][j - 1];
			}else{
				dp[i][j] = min(dp[i + 1][j] + cost[s[i] - B], dp[i][j - 1] + cost[s[j] - B]);
			}
		}
	}
	
	ans = dp[0][M - 1];
	printf("%d\n", ans);
	
	return 0;
	
}

