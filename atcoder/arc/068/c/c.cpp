// AtCoder Regular Contest 068
// C - X: Yet Another Die Game

#include <cstdio>

using namespace std;
typedef long long int ll;


ll X;
ll ans;

int main() {

  ll a, b;

  scanf("%lld", &X);
  a = X / 11;
  b = X - a * 11;
  if (b > 6) {
    ans = a * 2 + 2;
  } else if (b > 0) {
    ans = a * 2 + 1;
  } else {
    ans = a * 2;
  }

  printf("%lld\n", ans);

  return 0;

}


