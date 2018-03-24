// AtCoder Grand Contest 005
// B - Minimum Sum

#include <cstdio>
#include <algorithm>
#define MAX_N 200000
using namespace std;

typedef long long int ll;
typedef pair<int, int> PII;


class UnionFind{
  public:
    void init(int n);
    void unite(int a, int b);
    bool same(int a, int b);
    int left(int a);
    int right(int a);
  private:
    int root(int a);
    int par[MAX_N];
    int rank[MAX_N];
    int l[MAX_N], r[MAX_N];
};

void UnionFind::init(int n) {
  int i;

  for (i = 0; i < n; i++) {
    par[i] = i;
    l[i] = r[i] = i;
    rank[i] = 0;
  }
  return;
}

void UnionFind::unite(int a, int b) {
  a = root(a);
  b = root(b);
  if (a == b) {
    return;
  }
  if (rank[a] < rank[b]) {
    par[a] = b;
    l[b] = min(l[a], l[b]);
    r[b] = max(r[a], r[b]);
  } else {
    par[b] = a;
    l[a] = min(l[a], l[b]);
    r[a] = max(r[a], r[b]);
    if (rank[a] == rank[b]) {
      rank[a]++;
    }
  }
  return;
}

bool UnionFind::same(int a, int b) {
  return root(a) == root(b);
}

int UnionFind::root(int a) {
  if (par[a] != a) {
    par[a] = root(par[a]);
  }
  return par[a];
}

int UnionFind::left(int a) {
  return l[root(a)];
}

int UnionFind::right(int a) {
  return r[root(a)];
}


int N;
int A[MAX_N];
UnionFind uf;
ll ans;

int main() {

  PII a_sorted[MAX_N];
  int idx;

  scanf("%d", &N);
  uf.init(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    a_sorted[i] = make_pair(A[i], i);
  }
  sort(a_sorted, a_sorted + N);

  ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    idx = a_sorted[i].second;
    if (idx - 1 >= 0 && A[idx - 1] > A[idx]) {
      uf.unite(idx - 1, idx);
    }
    if (idx + 1 < N && A[idx + 1] > A[idx]) {
      uf.unite(idx + 1, idx);
    }
    // printf("A[%d] = %d, l: %d, r: %d\n", idx, A[idx], uf.left(idx), uf.right(idx));
    ans += (ll)(uf.right(idx) - idx + 1) * (idx - uf.left(idx) + 1) * A[idx];
  }

  printf("%lld\n", ans);

  return 0;

}


