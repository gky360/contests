// SegmentTree

#include <cstdio>
#include <algorithm>
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
  T query(int a, int b, int k);
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
T SegmentTree<T>::query(int a, int b, int k) {
  return query(a, b, k, 0, n);
}





class SegmentTree2D {
public:
  int w, h;
  SegmentTree<T> dat[2 * MAX_ELEMENTS - 1];
  void init(int _w, int _h);
  void update(int x, int y, T a);
  T query(int ax, int ay, int bx, int by, int k, int ly, int ry);
};

void SegmentTree2D::init(int _w, int _h) {
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

void SegmentTree2D::update(int x, int y, T a) {
  int k = y + h - 1;
}



int main() {


  return 0;

}


