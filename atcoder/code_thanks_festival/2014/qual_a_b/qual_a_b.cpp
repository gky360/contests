// code thanks festival 2014 予選A B - バッジ

#include <cstdio>
#include <algorithm>
using namespace std;


int N, A, B, C;
int ans;

int main() {

  scanf("%d%d%d%d", &N, &A, &B, &C);

  if (B < C) {
    swap(B, C);
  }
  if (A < B) {
    swap(A, B);
  }

  ans = N / (A + B + C);
  if ((A + B + C) * ans + A >= N) {
    ans = ans * 3 + 1;
  } else if ((A + B + C) * ans + A + B >= N) {
    ans = ans * 3 + 2;
  } else {
    ans = ans * 3 + 3;
  }

  printf("%d\n", ans);

  return 0;
}
