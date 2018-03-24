// AtCoder Regular Contest 073
// C - Sentou

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int ll;


int N;
ll T;
ll ans;

int main() {

  ll t, stops_at;

  scanf("%d%lld", &N, &T);
  stops_at = 0;
  ans = 0;
  for (int i = 0; i < N; i++) {
    scanf("%lld", &t);
    ans += T - max(stops_at - t, 0LL);
    stops_at = t + T;
  }

  printf("%lld\n", ans);

  return 0;

}


