// AtCoder Indeedなう（オープンコンテストB）
// E - Line up!

#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;

typedef long long ll;


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

void BIT::init(int num) {
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


int N;
ll H[MAX_N];
int sorted_h[MAX_N];
BIT bit;
ll ans;

int main() {

  int n;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &H[i]);
    sorted_h[i] = H[i];
  }
  sort(sorted_h, sorted_h + N);

  bit.init(N);
  ans = 0;
  for (int i = 0; i < N; i++) {
    n = (lower_bound(sorted_h, sorted_h + N, H[i]) - sorted_h) + 1;
    if (bit.sum(n) - bit.sum(n - 1) >= 1) {
      ans = -1;
      break;
    }
    ans += (i - bit.sum(n)) * H[i];
    bit.add(n, 1);
  }

  printf("%lld\n", ans);

  return 0;

}


