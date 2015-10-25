// 京都大学プログラミングコンテスト 2014 F - テレパシー

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX_N 1000
#define MAX_V MAX_N
#define MAX_UP 3000
#define EPS 1e-10
using namespace std;


int N;
int x[MAX_N], y[MAX_N], d[MAX_N], c[MAX_N];
// dp[v][up]: dfs していったときに、v を up 回強くするのに必要なコスト
int dp[MAX_N][MAX_UP];
int ans;


class Graph{
  public:
    void add_edge(int from, int to);
    int calc_cost();
  private:
    bool dfs(int v);
    vector<int> g[MAX_V];
    bool visited[MAX_V];
};

void Graph::add_edge(int from, int to){
  g[from].push_back(to);
  g[to].push_back(from);
  return;
}

int Graph::calc_cost() {
  memset(visited, 0, sizeof(visited));
  memset(dp, 0, sizeof(dp));

  dfs(0);

  return *min_element(dp[0], dp[0] + MAX_UP);
}

bool Graph::dfs(int v) {
  if (visited[v]) {
    return true;
  }
  visited[v] = true;

  for (int i = 0; i < (int)g[v].size(); i++) {
    int u = g[v][i];
    int up = max((int)ceil(-d[u] - d[v] + sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v])) - EPS), 0);

    if (dfs(u)) {
      continue;
    }
    for (int j = 0; j < MAX_UP; j++) {
      dp[v][j] += dp[u][max(up - j, 0)];
    }
  }

  for (int j = 0; j < MAX_UP; j++) {
    dp[v][j] += c[v] * j;
    if (j < 10) {
    }
  }

  return false;
}


int main(){

  Graph graph;
  int u, v;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &d[i], &c[i]);
  }
  for (int i = 0; i < N - 1; i++) {
    scanf("%d%d", &u, &v);
    graph.add_edge(u - 1, v - 1);
  }

  printf("%d\n", graph.calc_cost());

  return 0;

}


