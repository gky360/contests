// AtCoder Regular Contest 067
// F - Yakiniku Restaurants

#include <cstdio>
#include <algorithm>
#define MAX_N 5000
#define MAX_M 200
#define MAX_ELEMENTS (1 << 13) // > N
using namespace std;
typedef long long int ll;


template <typename T>
class SegmentTree {
public:
  int n;
  T dat[2 * MAX_ELEMENTS - 1];
  void init(int _n);
  void update(int k, T a);
  T query(int a, int b);
private:
  T query(int a, int b, int k, int l, int r);
};

template <typename T>
void SegmentTree<T>::init(int _n) {
  n = 1;
  while (n < _n) {
    n <<= 1;
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    dat[i] = 0;
  }
  return;
}

template <typename T>
void SegmentTree<T>::update(int k, T a) {
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
  return;
}

template <typename T>
T SegmentTree<T>::query(int a, int b) {
  return query(a, b, 0, 0, n);
}

// [a, b), [l, r)
template <typename T>
T SegmentTree<T>::query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) {
    return 0;
  }
  if (a <= l && r <= b) {
    return dat[k];
  }
  return max(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
}


int N, M;
SegmentTree<ll> st[MAX_M];
ll x[MAX_N];
ll ans;

int main() {

  ll a, b;
  int l, r;
  ll diff, mm, pre_h, h;

  scanf("%d%d", &N, &M);
  x[0] = 0;
  for (int i = 1; i < N; i++) {
    scanf("%lld", &a);
    x[i] = x[i - 1] + a;
  }
  for (int j = 0; j < M; j++) {
    st[j].init(N);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%lld", &b);
      st[j].update(i, b);
    }
  }

  ans = 0;
  l = 0;
  for (r = 1; r <= N; r++) {
    for (; l < N && l < r; l++) {
      h = 0;
      diff = 0;
      for (int j = 0; j < M; j++) {
        mm = st[j].query(l, r);
        h += mm;
        diff += st[j].query(l + 1, r) - mm;
      }
      h -= x[r - 1] - x[l];
      diff += x[l + 1] - x[l];
      ans = max(ans, h);
      if (diff < 0 && r < N) {
        break;
      }
    }
  }

  printf("%lld\n", ans);

  return 0;

}


