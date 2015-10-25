//poj3273.cpp
//PKU JudgeOnline
//poj3273 Monthly Expence

#include <cstdio>
#include <algorithm>
#define MAX_N 100000
#define MAX_MONEY 10000
using namespace std;


int N;
int M;
int money[MAX_N];

int main()
{
	int low, high, mid;
	int month;
	int exp;
	int i;

	low = 0;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%d", &money[i]);
		low = max(low, money[i] - 1);
	}
	high = MAX_MONEY * MAX_N;

	while (high - low > 1) {	// low < mid <= high
		mid = (high + low) / 2;
		month = 1;
		exp = 0;
		for (i = 0; i < N && month <= M; i++) {
			if (exp + money[i] <= mid) {
				exp += money[i];
			} else {
				exp = money[i];
				month++;
			}
		}
		if (month > M) {
			low = mid;
		} else {
			high = mid;
		}
	}

	printf("%d\n", high);

	return 0;
}


