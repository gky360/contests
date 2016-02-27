#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAX_N 100000


const int SEGMENTS = 1 << 17; // 10^5 をカバーする 2の累乗
const int INF = 100000000;

// ある特定の区間の最小値を求める
class RMQ {
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

void RMQ::init(int a_n) {
  n = 1;
  while (n < a_n) {
    n *= 2;
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    dat[i] = INF;
  }
}

void RMQ::update(int k, int a) {
  // 葉の節点
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

int RMQ::query(int a, int b) {
  return query(a, b, 0, 0, n);
}

// k は節点番号、[l, r) はその節点の範囲
int RMQ::query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) {
    return INF;
  }
  if (a <= l && r <= b) {
    return dat[k];
  }
  int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
  int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
  return min(vl, vr);
}


RMQ highs, lows;
int N;
char S[1 + MAX_N + 1];
int Q;
int middle[1+ MAX_N];
int qs[1 + MAX_N];

bool query(int l, int r) {
  int updowns = qs[r] - qs[l] - abs(middle[r] - middle[l]);
  int ups, summit;
  int ups_min, downs_min;
  if (updowns < 0) {
    return false;
  }
  if (updowns % 2 != 0) {
    return false;
  }
  ups = updowns / 2 + max(0, middle[l] - middle[r]);
  summit = max((int)(lower_bound(qs+ l, qs + r, qs[l] + ups) - qs), l);
  ups_min = highs.query(l, summit + 1);
  downs_min = lows.query(summit + 1, r + 1);
  return (ups_min == INF || ups_min == highs.query(l, l + 1))
      && (downs_min == INF || downs_min == lows.query(r, r + 1));
}

int main() {

  int high, low;
  int l, r;

  scanf("%d", &N);
  scanf("%s", S + 1);
  highs.init(N + 1);
  lows.init(N + 1);

  high = 0;
  low = 0;
  highs.update(0, 0);
  lows.update(0, 0);
  middle[0] = 0;
  qs[0] = 0;
  for (int i = 1; i <= N; i++) {
    middle[i] = middle[i - 1];
    qs[i] = qs[i - 1];
    switch(S[i]) {
      case '(':
        high++;
        low++;
        middle[i]++;
        break;
      case ')':
        high--;
        low--;
        middle[i]--;
        break;
      case '?':
        high++;
        low--;
        qs[i]++;
        break;
    }
    highs.update(i, high);
    lows.update(i, low);
  }

  scanf("%d", &Q);
  for (int q = 0; q < Q; q++) {
    scanf("%d%d", &l, &r);
    l--;
    printf("%s\n", query(l, r) ? "Yes" : "No");
  }

  return 0;
}


