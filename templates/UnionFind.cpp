// UnionFind.cpp
// UnionFind木用クラス
// int型

#include <cstdio>
#define MAX_N 1000000
using namespace std;


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


int main(){


  return 0;

}

