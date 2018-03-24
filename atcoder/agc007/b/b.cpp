// AtCoder Grand Contest 007
// B - Construct Sequences

#include <cstdio>
#define MAX_N 200000
#define MAX_BIT_IDX MAX_N
using namespace std;


typedef long long int ll;

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


int N;
LinearBIT<ll> l_bit[2];
int p[MAX_N + 1];


int main() {

  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &p[i]);
  }
  l_bit[0].init(N);
  l_bit[1].init(N);

  for (int i = 1; i <= N; i++) {
    l_bit[0].add(i, i + 1, i);
    l_bit[1].add(i, i + 1, N + 1 - i);
  }

  for (int i = 1; i <= N; i++) {
    l_bit[0].add(p[i], N + 1, i - 1);
    l_bit[1].add(1, p[i] + 1, i - 1);
  }

  for (int j = 0; j < 2; j++) {
    for (int i = 1; i <= N; i++) {
      printf("%lld%c", l_bit[j].sum(i) - l_bit[j].sum(i - 1), i < N ? ' ' : '\n');
    }
  }

  return 0;

}


