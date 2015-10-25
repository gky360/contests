//poj2068.cpp
//PKU JudgeOnline
//poj2068 Nim


#include <cstdio>
#include <cstring>
#include <algorithm>
#define NMAX 10
#define SMAX (1 << 13)
using namespace std;


int N;
int S;
int M[2 * NMAX];
bool dp[2 * NMAX][SMAX];

int main(){
	
	int i, j, k;
	
	while(true){
		scanf("%d", &N);
		if(N == 0){
			break;
		}
		scanf("%d", &S);
		for(i = 0; i < 2 * N; i++){
			scanf("%d", &M[i]);
		}
		
		memset(dp, 0, sizeof(dp));
		
		for(j = 0; j < S; j++){
			for(i = 2 * N - 1; i >= 0; i--){
				if(!dp[i][j]){
					for(k = j + 1; k <= min(j + M[(i + 2 * N - 1) % (2 * N)], S - 1); k++){
						dp[(i + 2 * N - 1) % (2 * N)][k] = true;
					}
				}
			}
		}
		
		printf("%d\n", dp[0][S - 1] ? 1 : 0);
		
	}
	
	return 0;
	
}


