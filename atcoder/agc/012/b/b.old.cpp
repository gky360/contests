// AtCoder Grand Contest 012
// B - Splatter Painting

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAX_N 100000
#define MAX_Q 100000
using namespace std;
typedef long long int ll;
typedef pair<int, int> PII;


int N, M, Q;
vector<int> G[MAX_N];
int nc[MAX_N], nq[MAX_N];
int v[MAX_Q], d[MAX_Q], c[MAX_Q];
int cnt;
queue<PII> q;

int main() {

  int a, b, cv, cd;

  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &a, &b);
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    scanf("%d%d%d", &v[i], &d[i], &c[i]);
    v[i]--;
  }
  memset(nc, 0, sizeof(nc));
  memset(nq, -1, sizeof(nq));

  cnt = 0;
  for (int j = Q - 1; j >= 0; j--) {
    q.push(PII(v[j], d[j]));
    while (!q.empty()) {
      cv = q.front().first;
      cd = q.front().second;
      q.pop();
      if (nq[cv] == j) {
        continue;
      }
      if (nc[cv] == 0) {
        cnt++;
      }
      if (nq[cv] < j) {
        nc[cv] = c[j];
      }
      nq[cv] = j;
      if (cd > 0) {
        for (int &to: G[cv]) {
          q.push(PII(to, cd - 1));
        }
      }
    }
    if (cnt >= N) {
      break;
    }
  }
  for (int i = 0; i < N; i++) {
    printf("%d\n", nc[i]);
  }

  return 0;

}


