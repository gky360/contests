// Paiza learning
// プログラミングスキルチェック
// C024:ミニ・コンピュータ

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int N;

int main() {

  int var[2];
  char command[4];
  int idx, a;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", command);
    if (strcmp(command, "SET") == 0) {
      scanf("%d%d", &idx, &a);
      var[idx - 1] = a;
    } else {
      scanf("%d", &a);
      if (strcmp(command, "ADD") == 0) {
        var[1] = var[0] + a;
      } else {
        var[1] = var[0] - a;
      }
    }
  }

  printf("%d %d\n", var[0], var[1]);

  return 0;

}


