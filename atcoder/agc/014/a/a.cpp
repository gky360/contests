// AtCoder Grand Contest 014
// A - Cookie Exchanges

#include <cstdio>
#include <algorithm>
#include <numeric>
#define MAX_N 3
using namespace std;
typedef long long int ll;

ll a[MAX_N];

int main() {

  ll tmp_a[MAX_N];
  ll sum, max_a;
  int j, m;
  bool is_odd;

  max_a = 0;
  for (int i = 0; i < MAX_N; i++) {
    scanf("%lld", &a[i]);
    max_a = max(max_a, a[i]);
  }
  for (m = 0; (1 << m) <= max_a; m++) {}
  for (j = 0; j <= m; j++) {
    is_odd = false;
    for (int i = 0; i < MAX_N; i++) {
      if (a[i] % (MAX_N - 1) != 0) {
        is_odd = true;
        break;
      }
    }
    if (is_odd) {
      break;
    }
    sum = accumulate(a, a + MAX_N, 0);
    swap(a, tmp_a);
    for (int i = 0; i < MAX_N; i++) {
      a[i] = (sum - tmp_a[i]) / (MAX_N - 1);
    }
  }
  if (is_odd) {
    printf("%d\n", j);
  } else {
    printf("%d\n", -1);
  }

  return 0;

}


