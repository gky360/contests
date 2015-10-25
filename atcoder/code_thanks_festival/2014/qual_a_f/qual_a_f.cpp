// code thanks festival 2014 予選A F - 順位表

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_N 50
#define MAX_V MAX_N


class Graph {
public:
  void init(int a_n);
  void add_edge(int from, int to);
  void dfs_start(int v);
  bool visited[MAX_V];
private:
  void dfs(int v);
  int n;
  vector<int> g[MAX_V];
};

void Graph::init(int a_n) {
  n = a_n;
}

void Graph::add_edge(int from, int to) {
  g[from].push_back(to);
}

void Graph::dfs_start(int v) {
  memset(visited, 0, sizeof(visited));
  dfs(v);
}

void Graph::dfs(int v) {
  if (visited[v]) {
    return;
  }
  visited[v] = true;
  for (int i = 0; i < (int)g[v].size(); i++) {
    dfs(g[v][i]);
  }
}


int N, M;
int ans;

int main() {

  Graph g;
  int a, b;

  scanf("%d%d", &N, &M);
  g.init(N);
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &a, &b);
    g.add_edge(b - 1, a - 1);
  }

  g.dfs_start(0);

  ans = 0;
  for (int i = 0; i < N; i++) {
    if (g.visited[i]) {
      ans++;
    }
  }

  printf("%d\n", ans);

  return 0;
}
