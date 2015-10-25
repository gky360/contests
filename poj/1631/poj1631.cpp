//poj1631.cpp
//PKU JudgeOnline
//poj1631 Bridging signals

#include <cstdio>
#include <algorithm>
#define PMAX 40000
#define INF 100000000
using namespace std;


int N;
int P;
int table[PMAX];
int ans;

int main(){
	
	int tmp;
	int i, j;
	
	scanf("%d", &N);
	for(j = 0; j < N; j++){
		scanf("%d", &P);
		fill(table, table + P, INF);
		for(i = 0; i < P; i++){
			scanf("%d", &tmp);
			*upper_bound(table, table + i, tmp) = tmp;
		}
		ans = lower_bound(table, table + P, INF) - table;
		printf("%d\n", ans);
	}
	
	return 0;
	
}

