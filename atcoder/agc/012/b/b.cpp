// AtCoder Grand Contest 012
// B - Splatter Painting

#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 100000
#define MAX_Q 100000
#define MAX_D 10
using namespace std;
typedef long long int ll;


int N, M, Q;
vector<int> G[MAX_N];
int dp[MAX_D + 1][MAX_N];
int C[MAX_Q + 1];

int main() {

  int a, b, v, d;

  memset(dp, 0, sizeof(dp));
  scanf("%d%d", &N, &M);
  for (int j = 0; j < M; j++) {
    scanf("%d%d", &a, &b);
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }
  scanf("%d", &Q);
  C[0] = 0;
  for (int k = 1; k <= Q; k++) {
    scanf("%d%d%d", &v, &d, &C[k]);
    dp[d][v - 1] = max(dp[d][v - 1], k);
  }

  for (int l = MAX_D; l > 0; l--) {
    for (int i = 0; i < N; i++) {
      dp[l - 1][i] = max(dp[l - 1][i], dp[l][i]);
      for (int &to: G[i]) {
        dp[l - 1][to] = max(dp[l - 1][to], dp[l][i]);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    printf("%d\n", C[dp[0][i]]);
  }

  return 0;

}


