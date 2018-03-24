// AtCoder Grand Contest 007
// D - Shik and Game

#include <cstdio>
#include <algorithm>
#define MAX_N 100000
#define MAX_ELEMENTS (1 << 17)
#define INF 1e18
using namespace std;


typedef long long int ll;

template <typename T>
class SegmentTree {
public:
  int n;
  T dat[2 * MAX_ELEMENTS - 1];
  void init(int _n);
  void update(int k, T a);
  T query(int a, int b, int k, int l, int r);
  T query(int a, int b);
};

template <typename T>
void SegmentTree<T>::init(int _n) {
  n = 1;
  while (n < _n) {
    n <<= 1;
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    dat[i] = INF;
  }
  return;
}

template <typename T>
void SegmentTree<T>::update(int k, T a) {
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
  return;
}

// [a, b), [l, r)
template <typename T>
T SegmentTree<T>::query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) {
    return INF;
  }
  if (a <= l && r <= b) {
    return dat[k];
  }
  return min(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
}

template <typename T>
T SegmentTree<T>::query(int a, int b) {
  return query(a, b, 0, 0, n);
}


int N, E, T;
SegmentTree<ll> st;
int x[MAX_N + 1];
ll dp[MAX_N + 1];

int main() {

  ll min_dx = INF;
  int j;

  scanf("%d%d%d", &N, &E, &T);
  x[0] = 0;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &x[i]);
  }
  dp[0] = 0;
  st.init(N);
  st.update(0, dp[0]);
  j = 0;
  for (int i = 1; i <= N; i++) {
    for (; (x[i] - x[j + 1]) * 2 > T; j++) {
      min_dx = min(min_dx, dp[j] - x[j + 1] * 2);
    }
    dp[i] = min_dx + x[i] * 2;
    dp[i] = min(dp[i], st.query(j, i) + T);
    st.update(i, dp[i]);
  }

  printf("%lld\n", dp[N] + E);

  return 0;

}


