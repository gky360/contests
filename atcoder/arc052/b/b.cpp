// AtCoder Regular Contest 052
// B - 円錐

#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX_N 100
#define MAX_X 10000
#define MAX_H 10000
#define MAX_BIT_IDX (MAX_X + MAX_H)
using namespace std;


template <typename T>
class BIT {
public:
  T bit[MAX_BIT_IDX + 1];
  int n;
private:
public:
  void init(int num);
  T sum(int i);
  void add(int i, T x);
private:
};

template <typename T>
void BIT<T>::init(int num) {
  n = num;
  for (int i = 0; i <= n; i++) {
    bit[i] = 0;
  }
  return;
}

template <typename T>
T BIT<T>::sum(int i) {
  T s = 0;

  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

template <typename T>
void BIT<T>::add(int i, T x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
  return;
}


int N, Q;
BIT<double> bit;
double ans;

int main() {

  int x, r, h;
  int a, b;

  scanf("%d%d", &N, &Q);
  bit.init(MAX_X + MAX_H);
  for (int i = 0; i < N; i++) {
    scanf("%d%d%d", &x, &r, &h);
    for (int j = 0; j < h; j++) {
      bit.add(x + j + 1, (double)r * r * M_PI * h * 1.0/3.0 * (pow(h - j, 3) - pow(h - j - 1, 3)) / pow(h, 3));
    }
  }

  for (int i = 0; i < Q; i++) {
    scanf("%d%d", &a, &b);
    ans = bit.sum(b) - bit.sum(a);
    printf("%lf\n", ans);
  }

  return 0;

}


