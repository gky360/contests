// 京都大学プログラミングコンテスト 2014 B - 数当てゲーム

#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 1000

bool dvs[MAX_N + 1];
char judge[2];
int ans;

int main() {

  memset(dvs, 1, sizeof(dvs));

  ans = 1;
  for (int i = 2; i <= MAX_N; i++) {
    if (!dvs[i]) {
      continue;
    }
    printf("? %d\n", i);
    fflush(stdout);
    scanf("%s", judge);

    if (judge[0] == 'Y') {
      ans = i;
    } else {
      for (int j = i; j < MAX_N; j += i) {
        dvs[j] = false;
      }
    }
  }

  printf("! %d\n", ans); fflush(stdout);

  return 0;
}
