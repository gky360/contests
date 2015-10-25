//poj3666.cpp
//PKU JudgeOnline
//poj3666 Making the Grade

#include <cstdio>
#include <algorithm>
#define NMAX 2000
#define INF 1 << 30
using namespace std;


int N;
int elv[NMAX];
int order[NMAX];
int dp[2][NMAX + 1];	// “Y‚¦Žš1‚©‚ç
int ans = INF;

int main(){
	
	int i, j, k;
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &elv[i]);
		order[i] = elv[i];
	}
	sort(order, order + N);
	
	for(k = 0; k < 2; k++){
		for(j = 1; j <= N; j++){
			dp[0][j] = 0;
		}
		dp[0][0] = dp[1][0] = INF;
		
		for(i = 1; i <= N; i++){
			for(j = 1; j <= N; j++){
				dp[i % 2][j] = min(dp[i % 2][j - 1], dp[(i - 1) % 2][j]);
			}
			for(j = 1; j <= N; j++){
				dp[i % 2][j] += abs(order[j - 1] - elv[i - 1]);
			}
			
		}
		for(j = 1; j <= N; j++){
			ans = min(ans, dp[N % 2][j]);
		}
		
		if(k == 0){
			for(i = 0; i < N - 1 - i; i++){
				swap(order[i], order[N - 1 - i]);
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
	
}


