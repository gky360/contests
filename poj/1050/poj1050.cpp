//poj1050.cpp
//PKU JudgeOnline
//poj1050 To the Max

#include <cstdio>
#include <algorithm>
#define NMAX 100
#define INF 100000000
using namespace std;

int N;
int sq[NMAX + 1][NMAX + 1];
int ans = -INF;

int main(){
	
	int s, t;
	int tmp;
	int i, j;
	
	scanf("%d", &N);
	for(i = 1; i <= N; i++){
		sq[i][0] = 0;
	}
	for(j = 1; j <= N; j++){
		for(i = 1; i <= N; i++){
			scanf("%d", &tmp);
			sq[i][j] = sq[i][j - 1] + tmp;
		}
	}
	
	for(s = 1; s <= N; s++){
		for(t = s; t <= N; t++){
			tmp = -INF;
			for(i = 1; i <= N; i++){
				if(tmp < 0){
					tmp = sq[i][t] - sq[i][s - 1];
				}else{
					tmp += sq[i][t] - sq[i][s - 1];
				}
				ans = max(ans, tmp);
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
	
}

