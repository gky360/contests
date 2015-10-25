//aoj0595.cpp
//AIZU ONLINE JUDGE
//aoj0595 Schedule

#include <cstdio>
#include <cstring>
#define NMAX 1000
#define J 1	//001
#define O 2	//010
#define I 4	//100
#define MOD 10007
//#define DBG 1
using namespace std;


int N;
int resp[NMAX + 1];
int dp[8][NMAX + 1];
int ans;

int main(){
	char tmp;
	int i, j, k;

	scanf("%d", &N);
	scanf("%*c");
	for(j = 1; j <= N; j++){
		scanf("%c", &tmp);
		switch(tmp){
		case 'J':
			resp[j] = J;
			break;
		case 'O':
			resp[j] = O;
			break;
		case 'I':
			resp[j] = I;
			break;
		}
#ifdef DBG
		printf("%d", resp[j]);
#endif
	}
#ifdef DBG
	printf("\n", resp[j]);
#endif
	resp[0] = J;

	memset(dp, 0, sizeof(dp));
	dp[J][0] = 1;

	for(j = 1; j <= N; j++){
		for(i = 1; i < 8; i++){
			for(k = 1; k < 8; k++){
				if((i & k) && (k & resp[j])){
					dp[k][j] = (dp[k][j] + dp[i][j - 1]) % MOD;
				}
			}
		}
	}

	ans = 0;
	for(i = 1; i < 8; i++){
		ans += dp[i][N];
	}
	ans %= MOD;

	printf("%d\n", ans);

	return 0;
}


