// 京都大学プログラミングコンテスト 2014 A - マッサージチェア

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int A[3], B[3];
int ans;

int main() {

  scanf("%d%d%d%d%d%d", &A[0], &A[1], &A[2], &B[0], &B[1], &B[2]);

  ans = 100000000;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == i) {
        continue;
      }
      for (int k = 0; k < 3; k++) {
        if (k == j || k == i) {
          continue;
        }
        ans = min(ans, abs(A[0] - B[i]) + abs(A[1] - B[j]) + abs(A[2] - B[k]));
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
