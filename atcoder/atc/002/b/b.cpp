// AtCoder Typical Contenst 002
// B - n^p mod m

#include <cstdio>
using namespace std;


long long int N, M, P;
long long int n_pow;
long long int ans;

int main() {

  scanf("%lld%lld%lld", &N, &M, &P);

  ans = 1;
  n_pow = N % M;
  for (; P > 0; P = P >> 1) {
    if (P & 1) {
      ans *= n_pow;
      ans %= M;
    }
    n_pow = n_pow * n_pow % M;
  }

  printf("%lld\n", ans);

  return 0;

}

