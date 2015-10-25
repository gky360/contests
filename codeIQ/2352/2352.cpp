// CodeIQ 2352
// 小数を分数p/qに近似しよう

#include <cstdio>
#include <cmath>
using namespace std;

double target;
int p, q;

int main () {
  double min_diff;
  int tmp_p, tmp_q;

  scanf("%lf", &target);

  min_diff = 10000000;
  for (tmp_q = 1; tmp_q < 1000000; tmp_q++) {
    tmp_p = target * tmp_q + 0.5;
    if (min_diff > fabs((double)tmp_p / tmp_q - target) && tmp_p < 1000000) {
      min_diff = fabs((double)tmp_p / tmp_q - target);
      p = tmp_p;
      q = tmp_q;
    }
  }

  printf("%d %d\n", p, q);

  return 0;

}


