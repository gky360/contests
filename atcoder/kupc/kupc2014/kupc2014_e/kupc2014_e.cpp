// 京都大学プログラミングコンテスト 2014 E - 何しちゃおっかな？

#include <cstdio>
using namespace std;


int C;

int main() {

  int n, m;

  for (scanf("%d", &C); C > 0; C--) {
    scanf("%d%d", &n, &m);
    if (m * n % 8 == 0 && m * n != 8 && m > 1 && n > 1) {
      printf("%s\n", "Possible");
    } else {
      printf("%s\n", "Impossible");
    }
  }

  return 0;
}
