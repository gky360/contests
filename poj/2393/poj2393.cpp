//poj2393.cpp
//PKU JudgeOnline
//poj2393 Yogurt factory

#include <cstdio>
#include <algorithm>
#define NMAX 10000
#define INF 100000000
using namespace std;


int N;
int S;
long long int ans;

int main(){
	
	int min_cost = INF;
	int c, y;
	int i;
	
	scanf("%d %d", &N, &S);
	ans = 0;
	for(i = 0; i < N; i++){
		scanf("%d %d", &c, &y);
		min_cost = min(min_cost, c - S * i);
		ans += (min_cost + S * i) * y;
	}
	
	printf("%lld\n", ans);
	
	return 0;
	
}

