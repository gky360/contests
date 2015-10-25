//poj3254.cpp
//PKU JudgeOnline
//poj3254 Corn Fields

#include <cstdio>
#define MMAX 12
#define NMAX 12
#define Z 100000000
using namespace std;

int M, N;
int farm;
int dp[2][1 << NMAX];
int ans;

int main(){
	
	int i, k;
	
	scanf("%d %d", &M, &N);
	for(k = 0; k < (1 << N); k++){
		dp[0][k] = 0;
	}
	scanf("%d", &farm);
	if(farm == 1){
		dp[0][1 << (N - 1)] = 1;
	}
	dp[0][0] = 1;
	for(i = 1; i < M * N; i++){
		for(k = 0; k < (1 << N); k++){
			dp[i % 2][k] = 0;
		}
		scanf("%d", &farm);
		for(k = 0; k < (1 << N); k++){
			if(farm == 1 && (i / N == 0 || (k & 1) == 0)
					&& (i % N == 0 || (k & (1 << (N - 1))) == 0)){
				dp[i % 2][(k >> 1) + (1 << (N - 1))]
						= (dp[i % 2][(k >> 1) + (1 << (N - 1))]
						+ dp[(i - 1) % 2][k]) % Z;
			}
			dp[i % 2][k >> 1] = (dp[i % 2][k >> 1] + dp[(i - 1) % 2][k]) % Z;
		}
	}
	
	ans = 0;
	for(k = 0; k < (1 << N); k++){
		ans = (ans + dp[(M * N - 1) % 2][k]) % Z;
	}
	printf("%d\n", ans);
	
	return 0;
	
}


