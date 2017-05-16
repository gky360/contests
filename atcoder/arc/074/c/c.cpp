// AtCoder Regular Contest 074
// C - Chocolate Bar

#include <cstdio>
#include <algorithm>
#define INF ((ll)1e17)
using namespace std;
typedef long long int ll;


ll hw[2];
ll ans;

int main() {

  ll x, a, b, c;

  scanf("%lld%lld", &hw[0], &hw[1]);

  ans = INF;
  for (int i = 0; i < 2; i++) {
    if (hw[0] > 2) {
      ans = min(ans, ((hw[0] + 2) / 3 - (hw[0] / 3)) * hw[1]);
    }
    for (int j = 0; j < 2; j++) {
      x = max((hw[0] + j) / 3, (ll)1);
      a = x * hw[1];
      b = (hw[0] - x) * (hw[1] / 2);
      c = (hw[0] - x) * ((hw[1] + 1) / 2);
      ans = min(ans, max(a, max(b, c)) - min(a, min(b, c)));
    }

    swap(hw[0], hw[1]);
  }

  printf("%lld\n", ans);

  return 0;

}


