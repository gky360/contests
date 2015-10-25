//poj3616.cpp
//PKU JudgeOnline
//poj3616 Milking Time

#include <cstdio>
#include <algorithm>
#define NMAX 1000000
#define MMAX 1000
using namespace std;


class interval
{
public:
	int start;
	int end;
	int efficiency;
	bool operator<(const interval& itvl);
};

bool interval::operator<(const interval& itvl)
{
	return end < itvl.end;
}


int N;
int M;
int R;
interval itvl[MMAX];
int dp[NMAX];

int main()
{
	int i, j;

	scanf("%d %d %d", &N, &M, &R);
	for(i = 0; i < M; i++){
		scanf("%d %d %d", &itvl[i].start, &itvl[i].end, &itvl[i].efficiency);
	}

	sort(itvl, itvl + M);

	return 0;


}


