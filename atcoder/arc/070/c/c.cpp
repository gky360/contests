// AtCoder Regular Contest 070
// C - Go Home

#include <cstdio>
#define MAX_X ((ll)1e9)
using namespace std;
typedef long long int ll;


ll X;

int main() {

  ll l, r, m, sum;

  scanf("%lld", &X);

  // (l, r]
  l = 0;
  r = MAX_X;
  while (r - l > 1) {
    m = (r + l + 1) / 2;
    sum = m * (m + 1) / 2;
    if (sum >= X) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%lld\n", r);

  return 0;

}


