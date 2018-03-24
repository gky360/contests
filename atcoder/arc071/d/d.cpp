// AtCoder Regular Contest 071
// D - 井井井 / ###

#include <cstdio>
#define MOD ((ll)1e9 + 7)
using namespace std;
typedef long long int ll;


int N, M;
ll ans;

int main() {

  ll x, y;
  ll sx, ssx, sy, ssy;

  scanf("%d%d", &N, &M);
  sx = 0; ssx = 0;
  for (int i = 0; i < N; i++) {
    scanf("%lld", &x);
    sx += x; sx %= MOD;
    ssx += x * (i + 1) - sx + MOD; ssx %= MOD;
  }
  ans = 0; sy = 0;
  for (int k = 0; k < M; k++) {
    scanf("%lld", &y);
    sy += y; sy %= MOD;
    ans += ((y * (k + 1) - sy + MOD) % MOD) * ssx % MOD; ans %= MOD;
  }
  printf("%lld\n", ans);

  return 0;

}


