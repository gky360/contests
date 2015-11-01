// Algorithms and Data Structures I
// 05 - Recursion / Divide and Conquer
// D - The Number of Inversions

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 200000


class BIT {
public:
  int bit[MAX_N + 1];
  int n;
private:
public:
  void init(int num);
  int sum(int i);
  void add(int i, int x);
private:
};

void BIT::init (int num) {
  n = num;
  for (int i = 0; i <= n; i++) {
    bit[i] = 0;
  }
  return;
}

int BIT::sum(int i) {
  int s = 0;

  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void BIT::add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
  return;
}


typedef long long int ll;

int N;
int origin[MAX_N], sorted[MAX_N];
BIT b;
ll ans;

int main(){

  int idx;

  scanf("%d", &N);
  b.init(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &origin[i]);
    sorted[i] = origin[i];
  }
  sort(sorted, sorted + N);

  ans = 0;
  for (int i = 0; i < N; i++) {
    idx = N - (lower_bound(sorted, sorted + N, origin[i]) - sorted);
    ans += b.sum(idx - 1);
    b.add(idx, 1);
  }

  printf("%lld\n", ans);

  return 0;

}


