// Paiza learning
// プログラミングスキルチェック
// C025:ファックスの用紙回収

#include <cstdio>
#include <algorithm>
using namespace std;


int M, N;
int ans;

int main() {

  int hh, mm, c;
  int pre_hh, sum_c;

  scanf("%d%d", &M, &N);
  sum_c = 0;
  ans = 0;
  for (int i = 0; i <= N; i++) {
    if (i < N) {
      scanf("%d%d%d", &hh, &mm, &c);
    } else {
      hh = 0;
    }
    if (pre_hh != hh) {
      ans += (sum_c + M - 1) / M;
      sum_c = 0;
    }
    sum_c += c;
    pre_hh = hh;
  }

  printf("%d\n", ans);

  return 0;

}


