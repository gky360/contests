// qualB_b.cpp
// CODE FESTIVAL 2014 予選B B - 歩く人

#include <cstdio>
using namespace std;


int N, K;
int ans;

int main() {

  int sum, a;

  scanf("%d%d", &N, &K);

  ans = -1;
  sum = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &a);
    sum += a;
    if (sum >= K && ans == -1) {
      ans = i + 1;
    }
  }

  printf("%d\n", ans);

  return 0;
}
