// Paiza learning
// プログラミングスキルチェック
// C021:暴風域にいますか？

#include <cstdio>
#include <algorithm>
using namespace std;


int XC, YC, R1, R2;
int N;

int main() {

  int x, y, rsq;

  scanf("%d%d%d%d", &XC, &YC, &R1, &R2);
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &x, &y);
    rsq = (x - XC) * (x - XC) + (y - YC) * (y - YC);
    printf("%s\n", (R1 * R1 <= rsq && rsq <= R2 * R2) ? "yes" : "no");
  }

  return 0;

}


