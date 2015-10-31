// Algorithms and Data Structures I
// 04 - Search
// D - Allocation

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100000
#define MAX_W 10000


int N, K;
int w_sum[MAX_N + 1];

int main() {

  int w;
  int r, l;
  int idx;

  scanf("%d%d", &N, &K);
  w_sum[0] = 0;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &w);
    w_sum[i] = w_sum[i - 1] + w;
  }

  // (l, r]
  l = 0;
  r = MAX_N * MAX_W;
  while (r - l > 1) {
    idx = 0;
    for (int k = 0; k < K && idx < N; k++) {
      idx = (upper_bound(w_sum + idx, w_sum + N + 1, w_sum[idx] + (r + l) / 2) - w_sum) - 1;
    }

    if (idx == N) {
      r = (r + l) / 2;
    } else {
      l = (r + l) / 2;
    }
  }

  printf("%d\n", r);

  return 0;

}


