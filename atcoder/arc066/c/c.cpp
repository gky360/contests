// AtCoder Regular Contest 066
// C - Lining Up

#include <cstdio>
#include <algorithm>
#define MAX_N 100000
#define MOD ((ll)1e9 + 7)
using namespace std;
typedef long long int ll;


int N;
int a[MAX_N];
ll ans;

int main() {

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  sort(a, a + N);

  ans = 1;
  for (int i = 0; i < N; i++) {
    if (a[i] != (i + N % 2) / 2 * 2 + (N + 1) % 2) {
      ans = 0;
      break;
    }
    ans *= (i % 2 == 1) ? 2 : 1;
    ans %= MOD;
  }

  printf("%lld\n", ans);

  return 0;

}


