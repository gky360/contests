// AtCoder Regular Contest 052
// D - 9

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define TH_K 100000
#define MAX_P 10
#define MAX_S (9 * MAX_P)
#define EPS 1e-8
using namespace std;

typedef long long int ll;


ll K, M;
ll dp[2][TH_K][MAX_S + 1];
int P;

int calc_d(ll m, int p) {
  return m / ((ll)pow(10, p)) % 10;
}

int calc_s(ll m) {
  int s = 0;
  for (; m > 0; m /= 10) {
    s += m % 10;
  }
  return s;
}

ll calc_dp() {
  ll m, ans;

  m = 0;
  memset(dp[1], 0, sizeof(dp[1]));
  dp[1][0][0] = 1;
  for (int p = P - 1; p >= 0; p--) {
    m = m * 10 + calc_d(M, p);

    memset(dp[0], 0, sizeof(dp[0]));
    for (int k = 0; k < K; k++) {
      for (int s = 0; s <= min((P - p) * 9, MAX_S); s++) {
        dp[0][k * 10 % K][s] += dp[1][k][s];
      }
    }

    memset(dp[1], 0, sizeof(dp[1]));
    for (int d = 0; d <= 9; d++) {
      for (int k = 0; k < K; k++) {
        for (int s = 0; s <= min((P - p) * 9, MAX_S); s++) {
          dp[1][(k + d) % K][s + d] += dp[0][k][s];
        }
      }
    }
    for (ll m_d = (m / 10 + 1) * 10 - 1; m_d > m; m_d--) {
      dp[1][m_d % K][calc_s(m_d)]--;
    }
  }

  ans = 0;
  for (int s = 0; s <= min(P * 9, MAX_S); s++) {
    ans += dp[1][s % K][s];
  }

  return ans - 1;
}

ll calc_mod() {
  ll ans;

  memset(dp[0], 0, sizeof(dp[0]));
  for (int s = 0; s <= min(P * 9, MAX_S); s++) {
    for (ll m = s; m <= M; m += K) {
      dp[0][s][calc_s(m)]++;
    }
  }

  ans = 0;
  for (int s = 0; s <= min(P * 9, MAX_S); s++) {
    ans += dp[0][s][s];
  }

  return ans - 1;
}

int main() {

  scanf("%lld%lld", &K, &M);
  P = (int)(log10(M) + EPS) + 1;

  if (K <= TH_K) {
    printf("%lld\n", calc_dp());
  } else {
    printf("%lld\n", calc_mod());
  }

  return 0;

}


