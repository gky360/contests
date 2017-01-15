// AtCoder Regular Contest 067
// D - Walk and Teleport

#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;
typedef long long int ll;


int N;
ll A, B;
ll x[MAX_N];
ll ans;

int main() {

  scanf("%d%lld%lld", &N, &A, &B);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &x[i]);
  }

  ans = 0;
  for (int i = 1; i < N; i++) {
    ans += min(A * (x[i] - x[i - 1]), B);
  }

  printf("%lld\n", ans);

  return 0;

}


