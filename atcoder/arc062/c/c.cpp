// AtCoder Regular Contest 062
// C - AtCoDeerくんと選挙速報 / AtCoDeer and Election Report

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int ll;


int N;
ll A, B;

int main() {

  ll a, b, p;

  scanf("%d", &N);
  A = B = 1;
  for (int i = 0; i < N; i++) {
    scanf("%lld%lld", &a, &b);
    p = max((A + a - 1) / a, (B + b - 1) / b);
    A = a * p;
    B = b * p;
  }

  printf("%lld\n", A + B);

  return 0;

}


