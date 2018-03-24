// AtCoder Regular Contest 066
// E - Addition and Subtraction Hard

#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX_N 100000
#define INF ((ll)1e18)
using namespace std;
typedef long long int ll;


int N;
ll dp[MAX_N][3];
ll ans;

int main() {

  ll a;
  int op;
  char c;

  scanf("%d", &N);
  scanf("%lld", &a);
  dp[0][0] = a;
  dp[0][1] = dp[0][2] = -INF;
  for (int i = 1; i < N; i++) {
    scanf(" %c %lld", &c, &a);
    op = (c == '-') ? 1 : 0;
    for (int j = 0; j <= 2; j++) {
      dp[i][j] = -INF;
      for (int k = j; k <= 2; k++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + (ll)pow(-1, k + op) * a);
      }
      if (op == 1 && j > 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (ll)pow(-1, j) * a);
      }
    }
  }

  ans = 0;
  for (int j = 0; j <= 2; j++) {
    ans = max(ans, dp[N - 1][j]);
  }

  printf("%lld\n", ans);

  return 0;

}


