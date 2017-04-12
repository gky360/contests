// AtCoder Grand Contest 011
// C - Squared Graph

#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 100000
using namespace std;
typedef long long int ll;


int N, M;
vector<int> G[MAX_N];
int color[MAX_N];
ll ans;

bool dfs(int v, int c) {
  bool is_bipartite = true;
  if (color[v] != 0) {
    return (color[v] == c);
  }
  color[v] = c;
  for (int e = 0; e < (int)G[v].size(); e++) {
    is_bipartite = dfs(G[v][e], -color[v]) && is_bipartite;
  }
  return is_bipartite;
}

int main() {

  int u, v;
  ll a, b, c;

  scanf("%d%d", &N, &M);
  for (int j = 0; j < M; j++) {
    scanf("%d%d", &u, &v);
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }
  memset(color, 0, sizeof(color));

  a = b = c = 0;
  for (int i = 0; i < N; i++) {
    if (color[i] != 0) {
      continue;
    }
    if (G[i].empty()) {
      c++;
      color[i] = 1;
    } else {
      if (dfs(i, 1)) {
        a++;
      } else {
        b++;
      }
    }
  }
  ans = (a + b) * (a + b) + a * a + 2 * N * c - c * c;
  printf("%lld\n", ans);

  return 0;

}


