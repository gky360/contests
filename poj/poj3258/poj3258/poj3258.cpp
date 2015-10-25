//poj3258.cpp
//PKU JudgeOnline
//poj3258 River Hopscotch

#include <cstdio>
#include <algorithm>
#define MAX_N 50000
using namespace std;


int L;
int N;
int M;
int rock[MAX_N + 1];

int main()
{
	int d;
	int x;
	int m;
	int l, r;
	int i;

	scanf("%d %d %d", &L, &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%d", &rock[i]);
	}
	rock[N] = L;
	sort(rock, rock + N + 1);

	l = 1;
	r = L + 1;
	while (r - l > 1) {	// “š‚¦‚Íl <= d < r ‚Ì”ÍˆÍ
		d = (l + r) / 2;
		x = 0;
		m = M;
		for (i = 0; i <= N && m >= 0; i++) {
			if (rock[i] >= x + d) {
				x = rock[i];
			} else {
				m--;
			}
		}
		if (m < 0) {
			r = d;
		} else {
			l = d;
		}
	}

	printf("%d\n", l);

	return 0;
}

