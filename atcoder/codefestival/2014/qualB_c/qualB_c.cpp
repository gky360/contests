// qualB_c.cpp
// CODE FESTIVAL 2014 予選B C - 錬金術士

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define ALPHABETS ('Z' - 'A' + 1)
#define MAX_S 100000
#define MAX_V (ALPHABETS + 4) // A -- Z, S1, S2, S, T
#define INF 100000000
using namespace std;


struct edge{
  int to, cap, rev; // 行き先, 容量, 逆辺番号
};

class Graph{
public:
  void add_edge(int from, int to, int cap);
  int max_flow(int s, int t);
private:
  void bfs(int s);
  int dfs(int v, int t, int f);
private:
  vector<edge> g[MAX_V];
  int level[MAX_V];
  int iter[MAX_V];
};

void Graph::add_edge(int from, int to, int cap){
  g[from].push_back((edge){to, cap, g[to].size()});
  g[to].push_back((edge){from, 0, g[from].size() - 1});
  return;
}

int Graph::max_flow(int s, int t){
  int f;
  int flow = 0;

  while(true){
    bfs(s);
    if(level[t] < 0){
      break;
    }
    memset(iter, 0, sizeof(iter));
    while((f = dfs(s, t, INF)) > 0){
      flow += f;
    }
  }
  return flow;
}

void Graph::bfs(int s){
  queue<int> que;
  int v;
  int i;

  memset(level, -1, sizeof(level));
  level[s] = 0;
  que.push(s);
  while(!que.empty()){
    v = que.front();
    que.pop();
    for(i = 0; i < (int)g[v].size(); i++){
      if(g[v][i].cap > 0 && level[g[v][i].to] < 0){
        level[g[v][i].to] = level[v] + 1;
        que.push(g[v][i].to);
      }
    }
  }
  return;
}

int Graph::dfs(int v, int t, int f){
  int d;

  if(v == t){
    return f;
  }
  for( ; iter[v] < (int)g[v].size(); iter[v]++){
    edge &e = g[v][iter[v]];
    if(e.cap > 0 && level[v] < level[e.to]){
      d = dfs(e.to, t, min(f, e.cap));
      if(d > 0){
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}


char S[3][MAX_S + 1];
int N;

int main() {

  // A -- Z : 0 -- 25
  const int s1 = ALPHABETS;
  const int s2 = ALPHABETS + 1;
  const int t  = ALPHABETS + 2;
  const int s  = ALPHABETS + 3;
  Graph g;
  int counts[ALPHABETS];

  for (int j = 0; j < 3; j++) {
    scanf("%s", S[j]);
  }
  N = strlen(S[0]) / 2;

  for (int j = 0; j < 3; j++) {
    memset(counts, 0, sizeof(counts));
    for (int i = 0; i < 2 * N; i++) {
      counts[S[j][i] - 'A']++;
    }
    for (int i = 0; i < ALPHABETS; i++) {
      if (counts[i] == 0) {
        continue;
      }
      if (j < 2) {
        // S1, S2
        g.add_edge(ALPHABETS + j, i, counts[i]);
      } else {
        // S3
        g.add_edge(i, ALPHABETS + j, counts[i]);
      }
    }
  }
  g.add_edge(s, s1, N);
  g.add_edge(s, s2, N);

  if (g.max_flow(s, t) == 2 * N) {
    puts("YES");
  } else {
    puts("NO");
  }

  return 0;
}
