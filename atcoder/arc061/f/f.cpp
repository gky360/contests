// AtCoder Regular Contest 061
// F - 3人でカードゲーム / Card Game for Three

#include <cstdio>
#include <cmath>
#define MAX_N (3 * 100000)
#define MAX_MK (3 * 100000)
#define MOD 1000000007
using namespace std;


typedef long long int ll;

int N;
int MK[2];
ll c0, c1, pow3;
ll ans;

int extgcd(int a, int b, int& x, int& y) {
  int d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}

int mod_inverse(int a, int m) {
  int x, y;
  extgcd(a, m, x, y);
  return (m + x) % m;
}

int main() {

  ll c1_edge[2];
  int inv3 = mod_inverse(3, MOD);

  scanf("%d%d%d", &N, &MK[0], &MK[1]);

  c0 = 1;
  c1 = 1;
  c1_edge[0] = 0;
  c1_edge[1] = 0;
  pow3 = 1;
  for (int i = 0; i < MK[0] + MK[1]; i++) {
    pow3 *= 3;
    pow3 %= MOD;
  }

  ans = 0;
  for (int p = N; p <= N + MK[0] + MK[1]; p++) {
    c1 = (c1 + 2 * MOD) % MOD;

    ans += ((c0 * c1) % MOD) * pow3;
    ans %= MOD;

    c0 = (c0 * ((p - 1) + 1) % MOD) * mod_inverse((p - 1) + 1 - (N - 1), MOD);
    c0 %= MOD;

    for (int i = 0; i <= 1; i++) {
      c1_edge[i] = (c1_edge[i] * (p - N)) % MOD * mod_inverse(p - N - MK[i], MOD);
      c1_edge[i] %= MOD;
      if (p - N == MK[i]) {
        c1_edge[i] = 1;
      }
    }
    c1 = c1 * 2 - c1_edge[0] - c1_edge[1] + 2 * MOD;
    c1 %= MOD;

    pow3 *= inv3;
    pow3 %= MOD;
  }

  printf("%lld\n", ans);

  return 0;

}


