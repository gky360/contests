#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 16


class UnionFind{
  public:
    void init(int n);
    void unite(int a, int b);
    bool same(int a, int b);
  private:
    int root(int a);
    int par[MAX_N];
    int rank[MAX_N];
};

void UnionFind::init(int n){
  int i;

  for(i = 0; i < n; i++){
    par[i] = i;
    rank[i] = 0;
  }
  return;
}

void UnionFind::unite(int a, int b){
  a = root(a);
  b = root(b);
  if(a == b){
    return;
  }
  if(rank[a] < rank[b]){
    par[a] = b;
  }else{
    par[b] = a;
    if(rank[a] == rank[b]){
      rank[a]++;
    }
  }
  return;
}

bool UnionFind::same(int a, int b){
  return root(a) == root(b);
}

int UnionFind::root(int a){
  if(par[a] != a){
    par[a] = root(par[a]);
  }
  return par[a];
}


int N, M;
bool G[MAX_N][MAX_N];
UnionFind uf;
int ans;

int main() {

  bool connected;
  int x, y;

  scanf("%d%d", &N, &M);
  memset(G, 0, sizeof(G));
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &x, &y);
    G[x - 1][y - 1] = true;
    G[y - 1][x - 1] = true;
  }

  ans = 0;
  for (int b = 0; b < (1 << N); b++) {
    uf.init(N);
    for (int p = 0; p < N; p++) {
      for (int q = p + 1; q < N; q++) {
        if ((((b >> p) & 1) ^ ((b >> q) & 1)) && G[p][q]) {
          uf.unite(p, q);
        }
      }
    }

    connected = true;
    for (int p = 1; p < N; p++) {
      if (!uf.same(0, p)) {
        connected = false;
        break;
      }
    }
    if (connected) {
      ans++;
    }
  }

  printf("%d\n", ans / 2);

  return 0;

}

