// AtCoder Grand Contest 012
// A - AtCoder Group Contest

#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;
typedef long long int ll;


int N;
ll a[3 * MAX_N];
ll ans;

int main() {

  scanf("%d", &N);
  for (int i = 0; i < 3 * N; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a, a + 3 * N, [](ll a, ll b) { return a > b; });

  ans = 0;
  for (int i = 0; i < N; i++) {
    ans += a[2 * i + 1];
  }
  printf("%lld\n", ans);


  return 0;

}


