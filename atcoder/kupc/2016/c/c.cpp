// Kyoto University Programming Contest 2016
// C - クッキー☆増殖装置 / Cookie Breeding Machine

#include <cstdio>
using namespace std;


int T, N, D;
int ans;

int main() {

  for (scanf("%d", &T); T > 0; T--) {
    scanf("%d%d", &N, &D);
    ans = (N - 1) * 127;
    ans += (N % 2 == 0) ? 127 - D : D;
    printf("%d\n", ans);
  }

  return 0;

}


