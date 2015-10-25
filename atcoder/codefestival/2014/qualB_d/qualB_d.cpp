// qualB_d.cpp
// CODE FESTIVAL 2014 予選B D - 登山家

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int SEGMENTS = 1 << 17; // 10^5 をカバーする 2の累乗
const int INF = 100000000;

// ある特定の区間の最小値を求める
class SegmentTree {
public:
  // a_n より大きい2の累乗 n を求めて初期化
  void init(int a_n);
  // 最小値を更新する
  void update(int k, int a);
  // [a, b) の最小値を求める
  int query(int a, int b);
private:
  int query(int a, int b, int k, int l, int r);
  // 要素数（2の累乗である必要がある）
  int n;
  int dat[2 * SEGMENTS - 1]; // SEGMENTS は 2の累乗である必要がある
};

void SegmentTree::init(int a_n) {
  n = 1;
  while (n < a_n) {
    n *= 2;
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    dat[i] = INF;
  }
}

void SegmentTree::update(int k, int a) {
  // 葉の節点
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

int SegmentTree::query(int a, int b) {
  return query(a, b, 0, 0, n);
}

// k は節点番号、[l, r) はその節点の範囲
int SegmentTree::query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) {
    return 0;
  }
  if (a <= l && r <= b) {
    return dat[k];
  }
  int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
  int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
  return min(vl, vr);
}


int N, H[MAX_N];
int ans;

int main() {

  SegmentTree seg;
  int l, r;

  scanf("%d", &N);
  seg.init(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &H[i]);
    seg.update(i, -H[i]);
  }

  for (int i = 0; i < N; i++) {
    ans = 0;

    // 左を調べる。(l, r]
    l = -1;
    r = i;
    while (r - l > 1) {
      if (-seg.query((r + l) / 2, i) <= H[i]) {
        r = (r + l) / 2;
      } else {
        l = (r + l) / 2;
      }
    }
    ans += i - r;

    // 右を調べる。[l, r)
    l = i;
    r = N;
    while (r - l > 1) {
      if (-seg.query(i + 1, (r + l) / 2 + 1) <= H[i]) {
        l = (r + l) / 2;
      } else {
        r = (r + l) / 2;
      }
    }
    ans += l - i;
    printf("%d\n", ans);
  }

  return 0;
}
