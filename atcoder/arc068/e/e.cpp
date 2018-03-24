// AtCoder Regular Contest 068
// E - Snuke Line

#include <cstdio>
#include <algorithm>
#define MAX_N 300000
#define MAX_M 100000
#define MAX_BIT_IDX (MAX_M + 1)
using namespace std;
typedef long long int ll;
typedef pair<int, int> Sec;


template <typename T>
class BIT {
public:
  T b[MAX_BIT_IDX + 1];
  int n;
  void init(int num);
  T sum(int i);
  void add(int i, T x);
};

template <typename T>
void BIT<T>::init(int num) {
  n = num;
  for (int i = 0; i <= n; i++) {
    b[i] = 0;
  }
  return;
}

template <typename T>
T BIT<T>::sum(int i) {
  T s = 0;

  for (; i > 0; i -= i & -i) {
    s += b[i];
  }
  return s;
}

template <typename T>
void BIT<T>::add(int i, T x) {
  for (; i <= n; i += i & -i) {
    b[i] += x;
  }
  return;
}


template <typename T>
class LinearBIT {
public:
  BIT<T> bit0, bit1;
  void init(int num);
  T sum(int i);
  void add(int l, int r, T x); // [l, r)
};

template <typename T>
void LinearBIT<T>::init(int num) {
  bit0.init(num);
  bit1.init(num);
  return;
}

// [l, r)
template <typename T>
void LinearBIT<T>::add(int l, int r, T x) {
  bit0.add(l, -x * (l - 1));
  bit1.add(l, x);
  bit0.add(r, x * (r - 1));
  bit1.add(r, -x);
  return;
}

template <typename T>
T LinearBIT<T>::sum(int i) {
  return bit1.sum(i) * i + bit0.sum(i);
}


int N, M;
Sec sec[MAX_N + 1];
LinearBIT<int> lb;
int ans;

int main() {

  int l, r, idx;

  scanf("%d%d", &N, &M);
  lb.init(M + 1);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &l, &r);
    sec[i].first = r - l;
    sec[i].second = l;
  }
  sec[N] = (Sec){ M, 0 };
  sort(sec, sec + N + 1);

  idx = 0;
  for (int d = 1; d <= M; d++) {
    ans = 0;
    for (; sec[idx].first < d; idx++) {
      l = sec[idx].second;
      r = l + sec[idx].first;
      lb.add(l, r + 1, 1);
    }
    ans = N - idx;
    for (int i = d; i <= M; i += d) {
      ans += lb.sum(i) - lb.sum(i - 1);
    }
    printf("%d\n", ans);
  }

  return 0;

}


