// Paiza learning
// プログラミングスキルチェック
// C015:ポイントカードの計算

#include <cstdio>
#include <algorithm>
using namespace std;


int N;
int ans;

int main() {

  int d, p;

  scanf("%d", &N);
  ans = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &d, &p);
    if (d % 10 == 3 || d / 10 == 3) {
      ans += p * 3 / 100;
    } else if (d % 10 == 5) {
      ans += p * 5 / 100;
    } else {
      ans += p / 100;
    }
  }

  printf("%d\n", ans);

  return 0;

}


