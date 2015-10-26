// Algorithms and Data Structures I
// 1 - Getting Started
// D - Maximum Profit

#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 1000000000


int N;
int ans;

int main() {

  int r_min, r;

  scanf("%d", &N);
  r_min = INF * 2;
  ans = -INF;
  for (int i = 0; i < N; i++) {
    scanf("%d", &r);
    ans = max(ans, r - r_min);
    r_min = min(r_min, r);
  }

  printf("%d\n", ans);

  return 0;

}


