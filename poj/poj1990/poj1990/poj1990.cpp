//poj1990.cpp
//PKU JudgeOnline
//poj1990 MooFest

#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#define MAX_N 20000
#define MAX_X 20000
using namespace std;


typedef long long LL;

class BinaryIndexedTree	// “Y‚¦š‚Í1n‚Ü‚è
{
public:
	BinaryIndexedTree::BinaryIndexedTree();
	int sum(int n);
	void add(int n, int val);
private:
	int bit[MAX_X + 1];
};

BinaryIndexedTree::BinaryIndexedTree()
{
	memset(bit, 0, sizeof(bit));
	return;
}

int BinaryIndexedTree::sum(int n)
{
	int res = 0;

	for (; n > 0; n -= n & -n) {
		res += bit[n];
	}
	return res;
}

void BinaryIndexedTree::add(int n, int val)
{
	for (; n <= MAX_X; n += n & -n) {
		bit[n] += val;
	}
	return;
}


int N;
pair<int, int> cow[MAX_N];	// (vol, x)
BinaryIndexedTree pos, num;	// xÀ•W, “ª”—p
LL ans;

int main()
{
	int x_sum;
	int x;
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &cow[i].first, &cow[i].second);
	}

	sort(cow, cow + N);

	ans = 0;
	for (i = 0; i < N; i++) {
		x = cow[i].second;
		x_sum = (2 * num.sum(x) - num.sum(MAX_X)) * x + pos.sum(MAX_X) - 2 * pos.sum(x);
		ans += (LL)x_sum * cow[i].first;
		pos.add(x, x);
		num.add(x, 1);
	}

	printf("%lld\n", ans);

	return 0;
}


