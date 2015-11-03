// Paiza learning
// プログラミングスキルチェック
// C013:嫌いな数字

#include <cstdio>
#include <algorithm>
using namespace std;


int N, M;

int main() {

  int r, tmp_r;
  bool is_none;
  bool is_hated;

  scanf("%d%d", &N, &M);
  is_none = true;
  for (int i = 0; i < M; i++) {
    scanf("%d", &r);
    is_hated = false;
    for (tmp_r = r ; tmp_r > 0; tmp_r /= 10) {
      if (tmp_r % 10 == N) {
        is_hated = true;
        break;
      }
    }
    if (!is_hated) {
      is_none = false;
      printf("%d\n", r);
    }
  }
  if (is_none) {
    printf("none\n");
  }

  return 0;

}