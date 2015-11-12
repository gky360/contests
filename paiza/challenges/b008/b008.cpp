// Paiza learning
// プログラミングスキルチェック
// B008:地下アイドルの夢

#include <cstdio>
#include <algorithm>
using namespace std;


int N, M;
int ans;

int main() {

  int event_prof;
  int e;

  scanf("%d%d", &N, &M);
  ans = 0;
  for (int i = 0; i < M; i++) {
    event_prof = 0;
    for (int j = 0; j < N; j++) {
      scanf("%d", &e);
      event_prof += e;
    }
    ans += max(event_prof, 0);
  }

  printf("%d\n", ans);

  return 0;

}


