// AtCoder Regular Contest 069
// C - Scc Puzzle

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int ll;


ll N, M;
ll ans;

int main() {

  ll x;

  scanf("%lld%lld", &N, &M);
  x = max((M - 2 * N) / 4, (ll)0);
  ans = min(N + x, M / 2 - x);

  printf("%lld\n", ans);

  return 0;

}


