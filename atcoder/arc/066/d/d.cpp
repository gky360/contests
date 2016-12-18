// AtCoder Regular Contest 066
// D - Xor Sum

#include <cstdio>
#include <cstring>
#define MAX_D 64
#define MOD ((ll)1e9 + 7)
using namespace std;
typedef long long int ll;


ll N;
ll dp[MAX_D][3];
ll ans;

int main() {

  int next_j;

  scanf("%lld", &N);

  memset(dp, 0, sizeof(dp));
  dp[MAX_D - 1][0] = 1;
  for (int i = MAX_D - 1; i > 0; i--) {
    for (int j = 0; j <= 2; j++) {
      for (int dv = 0; dv <= 2; dv++) {
        next_j = j * 2 + ((N >> (i - 1)) & 1) - dv;
        if (next_j < 0) {
          continue;
        }
        next_j = next_j > 2 ? 2 : next_j;
        dp[i - 1][next_j] += dp[i][j];
        dp[i - 1][next_j] %= MOD;
      }
    }
  }

  ans = 0;
  for (int j = 0; j <= 2; j++) {
    ans += dp[0][j];
    ans %= MOD;
  }

  printf("%lld\n", ans);

  return 0;

}


