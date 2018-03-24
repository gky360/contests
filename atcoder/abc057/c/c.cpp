// AtCoder Beginner Contest 057
// C - Digits in Multiplication

#include <cstdio>

using namespace std;
typedef long long int ll;


ll N;
int ans;

int main() {

  ll a, b;

  scanf("%lld", &N);
  for (ll i = 1; i * i <= N; i++) {
    if (N % i != 0) {
      continue;
    }
    a = i;
  }
  b = N / a;

  ans = 0;
  while (b > 0) {
    ans++;
    b /= 10;
  }

  printf("%d\n", ans);

  return 0;

}


