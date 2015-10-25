//poj3292.cpp
//PKU JudgeOnline
//poj3292 Semi-prime H-numbers

#include <cstdio>
#include <cstring>
#include <vector>
#define HMAX 1000001
typedef long long LL;
using namespace std;


int H;
bool table[HMAX / 4 + 1];
vector<int> prime;
int ans[HMAX / 4 + 1];

LL h_mul(int a, int b)
{
	return (LL)(4 * a + 1) * (4 * b + 1) / 4;
}

int main()
{
	
	int i, j;

	memset(table, 0, sizeof(table));
	memset(ans, 0, sizeof(ans));

	for(i = 1; i <= HMAX / 4; i++){
		if(table[i]){
			continue;
		}
		prime.push_back(i);
		for(j = i; h_mul(i, j) <= HMAX / 4; j++){
			table[h_mul(i, j)] = true;
		}
	}

	for(i = 0; i < prime.size(); i++){
		for(j = i; j < prime.size() && h_mul(prime[i], prime[j]) <= HMAX / 4; j++){
			ans[h_mul(prime[i], prime[j])] = 1;
		}
	}
	for(i = 1; i <= HMAX / 4; i++){
		ans[i] += ans[i - 1];
	}

	while(scanf("%d", &H) && H != 0){
		printf("%d %d\n", H, ans[H / 4]);
	}

	return 0;
}

