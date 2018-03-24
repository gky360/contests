// AtCoder Grand Contest 011
// A - Airport Bus

#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;
typedef long long int ll;


int N;
ll C, K;
ll T[MAX_N];
int ans;

int main() {

  ll cnt, lim_t;

  scanf("%d%lld%lld", &N, &C, &K);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &T[i]);
  }
  sort(T, T + N);

  ans = 1;
  cnt = 1;
  lim_t = T[0];
  for (int i = 1; i < N; i++) {
    if (cnt >= C || lim_t + K < T[i]) {
      ans++;
      cnt = 1;
      lim_t = T[i];
    } else {
      cnt++;
    }
  }

  printf("%d\n", ans);

  return 0;

}


