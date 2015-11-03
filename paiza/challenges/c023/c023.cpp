// Paiza learning
// プログラミングスキルチェック
// C023:クジの当選番号

#include <cstdio>
#include <algorithm>
using namespace std;


int N;
int ans;

int main() {

  int lott[6], test[6];

  for (int i = 0; i < 6; i++) {
    scanf("%d", &lott[i]);
  }
  scanf("%d", &N);
  for (int k = 0; k < N; k++) {
    for (int j = 0; j < 6; j++) {
      scanf("%d", &test[j]);
    }

    ans = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        if (lott[i] == test[j]) {
          ans++;
        }
      }
    }

    printf("%d\n", ans);
  }

  return 0;

}


