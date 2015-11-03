// Paiza learning
// プログラミングスキルチェック
// C022:ローソク足

#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 100000000


int N;
int S, E, H, L;

int main() {

  int s, e, h, l;

  scanf("%d", &N);
  S = -1;
  H = 0;
  L = INF;
  for (int i = 0; i < N; i++) {
    scanf("%d%d%d%d", &s, &e, &h, &l);
    if (S < 0) {
      S = s;
    }
    E = e;
    H = max(H, h);
    L = min(L, l);
  }

  printf("%d %d %d %d\n", S, E, H, L);

  return 0;

}


