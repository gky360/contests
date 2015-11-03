// Paiza learning
// プログラミングスキルチェック
// C020:残り物の量

#include <cstdio>
#include <algorithm>
using namespace std;


int main() {

  int m, p, q;

  scanf("%d%d%d", &m ,&p, &q);
  printf("%.10lf\n", (double)m * (100 - p) * (100 - q) * 0.0001);

  return 0;

}


