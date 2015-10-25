// CodeIQ 1561
// 「エース・ナンバー」問題

#include <cstdio>
using namespace std;

#define D 1000000
#define MAX_LOG_N 34
typedef long long ll;


ll n;
int pow16[MAX_LOG_N]; // pow16[i] = 16^(2^i)
int f[MAX_LOG_N]; // f[i] = 16^(2^i)
int ans;

int main () {
  int i;

  scanf("%lld", &n);

  pow16[0] = 16;
  f[0] = 10;
  for (i = 1; (ll)1 << i <= n; i++) {
    pow16[i] = (int)((ll)pow16[i - 1] * pow16[i - 1] % D);
    f[i] = (int)(((ll)pow16[i - 1] * f[i - 1] + f[i - 1]) % D);
  }

  ans = 0;
  for (i = 0; (ll)1 << i <= n; i++) {
    if (n & ((ll)1 << i)) {
      ans = (int)(((ll)ans * pow16[i] + f[i]) % D);
    }
  }

  printf("%d\n", ans);

  return 0;
}

