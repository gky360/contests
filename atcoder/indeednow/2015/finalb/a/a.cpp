// AtCoder Indeedなう（オープンコンテストB）
// A - Counting on a Triangle

#include <cstdio>
#define M 1000000007
using namespace std;


typedef long long int ll;

int A, B;
ll ans;

int main() {

  scanf("%d%d", &A, &B);

  ans = 0;
  for (ll n = A; n <= B; n++) {
    ans += n * n * (n + 1) / 2;
    ans %= M;
  }

  printf("%lld\n", ans);

  return 0;

}


