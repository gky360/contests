// AtCoder Regular Contest 067
// E - Grouping

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_N 1000
#define MOD ((ll)1e9 + 7)
using namespace std;
typedef long long int ll;


ll extgcd(ll a, ll b, ll& x, ll& y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}

ll inv(ll a, ll m) {
  ll x, y;
  extgcd(a, m, x, y);
  return (m + x) % m;
}


int N, A, B, C, D;
ll fac[MAX_N + 1];
ll inv_fac[MAX_N + 1];
ll dp[MAX_N + 1][MAX_N + 1];
ll ans;

int main() {

  int max_k;
  ll tmp, inv_fac_i_pow_k;

  scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);

  fac[0] = 1;
  inv_fac[0] = inv(fac[0], MOD);
  for (int i = 1; i <= N; i++) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= MOD;
    inv_fac[i] = inv(fac[i], MOD);
  }

  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      inv_fac_i_pow_k = 1;
      dp[i][j] = 0;
      max_k = (A <= i && i <= B) ? min(D, j / i) : 0;
      for (int k = 0; k <= max_k; k++) {
        if (k == 0 || C <= k) {
          tmp = dp[i - 1][j - i * k];
          tmp *= fac[N - j + i * k]; tmp %= MOD;
          tmp *= inv_fac[N - j]; tmp %= MOD;
          tmp *= inv_fac_i_pow_k; tmp %= MOD;
          tmp *= inv_fac[k]; tmp %= MOD;
          dp[i][j] += tmp; dp[i][j] %= MOD;
        }
        inv_fac_i_pow_k *= inv_fac[i];
        inv_fac_i_pow_k %= MOD;
      }
    }
  }

  ans = (dp[B][N] - dp[A - 1][N] + MOD) % MOD;
  printf("%lld\n", ans);

  return 0;

}


