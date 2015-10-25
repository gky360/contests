// 京都大学プログラミングコンテスト 2015 F - 逆ポーランド記法

#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

#define MAX_N 100


// 左、右の子の idx。子が存在しない場合は lc[v] == v や rc[v] == v。
int root;
int lc[MAX_N], rc[MAX_N];
int node[MAX_N];

int N;
char str[MAX_N + 1];

int main() {

  stack<int> s;
  queue<int> q;
  int l, r;

  scanf("%s", str);
  N = strlen(str);

  for (int i = 0; i < N; i++) {
    lc[i] = i;
    rc[i] = i;
  }
  for (int i = 0; i < N; i++) {
    node[i] = str[i] - '0';
    if (isdigit(str[i])) {
      s.push(i);
    } else {
      r = s.top(); s.pop();
      l = s.top(); s.pop();
      lc[i] = l;
      rc[i] = r;
      s.push(i);
    }
  }
  root = N - 1;

  int i = N - 1;
  int v = root;
  str[N] = '\0';
  q.push(v);
  while (!q.empty()) {
    v = q.front(); q.pop();
    str[i] = '0' + node[v];
    i--;
    if (lc[v] != v) {
      q.push(lc[v]);
    }
    if (rc[v] != v) {
      q.push(rc[v]);
    }
  }

  printf("%s\n", str);

  return 0;

}


