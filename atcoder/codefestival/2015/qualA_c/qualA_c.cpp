// qualA_c.cpp
// CODE FESTIVAL 2015 予選A C - 8月31日

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int N, T;
int C[MAX_N + 1];
int sum;
int ans;

int main() {

  int a, b;
  scanf("%d%d", &N, &T);

  sum = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &a, &b);
    sum += a;
    C[i] = b - a;
  }

  sort(C, C + N);

  for (ans = 0; sum > T; ans++) {
    if (ans == N) {
      ans = -1;
      break;
    }
    sum += C[ans];
  }

  printf("%d\n", ans);

  return 0;

}
