//poj1466.cpp
//PKU Judge Online
//poj1466 Girls and Boys

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_V 500

class Graph{
public:
  vector<int> g[MAX_V];
  int V;
  void init(int v);
  void add_edge(int a, int b);
  int bipartite_matching();
private:
  int match[MAX_V];
  bool used[MAX_V];
  bool dfs(int v);
};

void Graph::init(int v){
  int i;
  V = v;
  for(i = 0; i < V; i++){
    g[i].clear();
  }
  return;
}

void Graph::add_edge(int a, int b){
  g[a].push_back(b);
  return;
}

int Graph::bipartite_matching(){
  int v;
  int res;

  memset(match, -1, sizeof(match));
  res = 0;
  for(v = 0; v < V; v++){
    if(match[v] < 0){
      memset(used, 0, sizeof(used));
      if(dfs(v)){
        res++;
      }
    }
  }
  return res;
}

bool Graph::dfs(int v){
  int u, w;
  int i;

  used[v] = true;
  for(i = 0; i < g[v].size(); i++){
    u = g[v][i];
    w = match[u];
    if(w < 0 || (!used[w] && dfs(w))){
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

int main(){

  Graph G;
  int i;
  int tmp;
  int a, b;

  while(scanf("%d", &tmp) > 0){
    G.init(tmp);
    for(a = 0; a < G.V; a++){
      scanf("%*d: (%d)", &tmp);
      for(i = 0; i < tmp; i++){
        scanf("%d", &b);
        G.add_edge(a, b);
      }
    }

    printf("%d\n", G.V - G.bipartite_matching());
  }

  return 0;
}