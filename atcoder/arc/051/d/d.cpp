// AtCoder Regular Contest 051
// D - 長方形

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_W 2000
#define MAX_H 2000
#define MAX_ELEMENTS (1 << 11)
#define INF 1000000000
using namespace std;


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
  if (a <= l && b <= r) {
    return dat[k];
  }
  return min(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
}

template <typename T>
T SegmentTree<T>::query(int a, int b) {
  return query(a, b, 0, 0, n);
}


template <typename T>
class SegmentTree2D {
public:
  int w, h;
  SegmentTree<T> dat[2 * MAX_ELEMENTS - 1];
  void init(int _w, int _h);
  void update(int x, int y, T a);
  T query(int ax, int ay, int bx, int by, int k, int ly, int ry);
  T query(int ax, int ay, int bx, int by);
};

template <typename T>
void SegmentTree2D<T>::init(int _w, int _h) {
  w = 1;
  while (w < _w) {
    w <<= 1;
  }
  h = 1;
  while (h < _h) {
    h <<= 1;
  }
  for (int i = 0; i < 2 * h - 1; i++) {
    dat[i].init(w);
  }
  return;
}

template <typename T>
void SegmentTree2D<T>::update(int x, int y, T a) {
  int k = y + h - 1;
  dat[k].update(x, a);
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k].update(x, min(dat[k * 2 + 1].dat[x + w - 1], dat[k * 2 + 2].dat[x + w - 1]));
  }
  return;
}

template <typename T>
T SegmentTree2D<T>::query(int ax, int ay, int bx, int by, int k, int ly, int ry) {
  if (ry <= ay || by <= ly) {
    return INF;
  }
  if (ay <= ly && by <= ry) {
    return dat[k].query(ax, bx);
  }
  return min(query(ay, by, k * 2 + 1, ly, (ly + ry) / 2), query(ay, by, k * 2 + 2, (ly + ry) / 2, ry));
}

template <typename T>
T SegmentTree2D<T>::query(int ax, int ay, int bx, int by) {
  return query(ax, ay, bx, by, 0, 0, h);
}


typedef long long int ll;

int W, H;
ll AB[MAX_W][MAX_H];
int Q, A, B;
SegmentTree2D<ll> seg2d_min, seg2d_max;

ll find(int ax, int ay, int bx, int by) {
  int my = (ay + by) / 2;
  for (int x = ax; x < bx; x++) {


  }
}

int main() {

  int a, b;

  scanf("%d%d", &W, &H);
  seg2d_min.init(W, H);
  seg2d_max.init(W, H);
  memset(AB, 0, sizeof(AB));
  for (int i = 0; i < W; i++) {
    scanf("%d", &a);
    for (int j = 0; j < H; j++) {
      AB[i][j] += a;
    }
  }
  for (int j = 0; j < H; j++) {
    scanf("%d", &b);
    for (int i = 0; i < W; i++) {
      AB[i][j] += b;
    }
  }

  for (int i = 0; i < W; i++) {
    for (int j = 1; j < H; j++) {
      AB[i][j] += AB[i][j - 1];
    }
  }
  for (int j = 0; j < H; j++) {
    seg2d_min.update(0, j, AB[0][j]);
    seg2d_max.update(0, j, -AB[0][j]);
    for (int i = 1; i < W; i++) {
      AB[i][j] += AB[i - 1][j];
      seg2d_min.update(i, j, AB[i][j]);
      seg2d_max.update(i, j, -AB[i][j]);
    }
  }

  scanf("%d", &Q);
  for (int q = 0; q < Q; q++) {
    scanf("%d%d", &A, &B);

  }


  return 0;

}


