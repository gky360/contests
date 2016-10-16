// CODE FESTIVAL 2016 qual B
// E - Lexicographical disorder

#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#define MAX_N 100000
#define MAX_SUM_S 400000
#define MAX_V (MAX_SUM_S + MAX_N + 1) // 文字 + 終端文字 + root
#define ALPH 26
using namespace std;


int N, Q;
string ss[MAX_N];
vector<int> g[MAX_V];
char node_c[MAX_V];
int node_i[MAX_V];
int q_order[ALPH + 1];
int new_node_id, node_id, next_node_id;
int cnt[MAX_N][ALPH + 1][ALPH + 1];
int ans;

int main() {

  char buff[MAX_SUM_S + 2];
  bool found;
  int k;

  scanf("%d", &N);
  node_c[0] = ' ';
  node_i[0] = 0;
  new_node_id = 1;
  for (int i = 0; i < N; i++) {
    scanf("%s", buff);
    ss[i] = string(buff);
    ss[i] += '{';
    node_i[0]++;
    node_id = 0;
    for (int j = 0; j < (int)ss[i].size(); j++) {
      found = false;
      for (int e = 0; e < (int)g[node_id].size(); e++) {
        if (node_c[g[node_id][e]] == ss[i][j]) {
          node_i[g[node_id][e]]++;
          node_id = g[node_id][e];
          found = true;
          break;
        }
      }
      if (!found) {
        g[node_id].push_back(new_node_id);
        node_c[new_node_id] = ss[i][j];
        node_i[new_node_id] = 1;
        node_id = new_node_id;
        new_node_id++;
      }
    }
  }

  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < N; i++) {
    node_id = 0;
    for (int j = 0; j < (int)ss[i].size(); j++) {
      for (int e = 0; e < (int)g[node_id].size(); e++) {
        cnt[i][node_c[g[node_id][e]] - 'a'][ss[i][j] - 'a'] += node_i[g[node_id][e]];
        if (node_c[g[node_id][e]] == ss[i][j]) {
          next_node_id = g[node_id][e];
        }
      }
      node_id = next_node_id;
    }
  }

  q_order[ALPH] = -1;
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    scanf("%d %s", &k, buff);
    k--;
    for (int j = 0; j < ALPH; j++) {
      q_order[buff[j] - 'a'] = j;
    }

    ans = 0;
    for (int c1 = 0; c1 < ALPH + 1; c1++) {
      for (int c2 = 0; c2 < ALPH + 1; c2++) {
        if (q_order[c1] < q_order[c2]) {
          ans += cnt[k][c1][c2];
        }
      }
    }
    ans++;
    printf("%d\n", ans);
  }

  return 0;

}


