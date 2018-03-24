// AtCoder Regular Contest 070
// D - No Need

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_N 5000
#define MAX_K 5000
using namespace std;
typedef long long int ll;


int N, K;
ll A[MAX_N + 2];
bool dp[2][MAX_N + 2][MAX_K + 1];
int ans;

int main() {

  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; i++) {
    scanf("%lld", &A[i]);
  }
  memset(dp, 0, sizeof(dp));

  for (int z = 0; z < 2; z++) {
    dp[z][(z ? N + 1 : 0)][0] = true;
    for (int i = (z ? N : 1); (z ? (i >= 1) : (i <= N)); i += -2 * z + 1) {
      for (int j = 0; j <= K; j++) {
        dp[z][i][j] = dp[z][i + 2 * z - 1][j];
        if (j - A[i] >= 0) {
          dp[z][i][j] = dp[z][i][j] || dp[z][i + 2 * z - 1][j - A[i]];
        }
      }
    }
  }

  ans = 0;
  for (int i = 1; i <= N; i++) {
    int j0, j1, tmp_k;
    j1 = K;
    tmp_k = 0;
    for (j0 = 0; j0 <= K; j0++) {
      if (!dp[0][i - 1][j0]) {
        continue;
      }
      for (; j1 >= 0; j1--) {
        if (!dp[1][i + 1][j1]) {
          continue;
        }
        if (j0 + j1 < K) {
          tmp_k = max(tmp_k, j0 + j1);
          break;
        }
      }
    }
    if (tmp_k < K - A[i]) {
      ans++;
    }
  }

  printf("%d\n", ans);

  return 0;

}


