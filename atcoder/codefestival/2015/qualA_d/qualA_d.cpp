// qualA_d.cpp
// CODE FESTIVAL 2015 予選A D - 壊れた電車

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_M 100000
typedef long long ll;

int N, M;
int X[MAX_M];

bool can_do_in(ll t) {

  ll reach = 1; // どこまで修理が終わっているか

  for (int i = 0; i < M; i++) {
    if (X[i] - reach > t) {
      return false;
    }
    if (X[i] - reach <= t / 3) {
      reach = X[i] + t - max(X[i] - reach, (ll)0) * 2 + 1;
    } else {
      reach = X[i] + (t - (X[i] - reach)) / 2 + 1;
    }
    if (reach > N) {
      return true;
    }
  }

  return false;
}

int main() {

  ll l, r;

  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d", &X[i]);
  }

  l = -1;
  r = N * 2;
  while (r - l > 1) {
    if (can_do_in((r + l) / 2)) {
      r = (r + l) / 2;
    } else {
      l = (r + l) / 2;
    }
  }

  printf("%lld\n", r);

  return 0;

}
