//max_flow.cpp
//最大流を求める
//グラフは隣接リスト型

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_V 100
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


int main(){
  return 0;
}

