// Paiza learning
// プログラミングスキルチェック
// B009:カンファレンスのタイムテーブル作成

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 10
#define MAX_LENGTH 16

int N;
char s[MAX_N][MAX_LENGTH];
int a[MAX_N];

int main() {

  int now;
  bool already;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s%d", s[i], &a[i]);
  }

  now = 10 * 60;
  already = false;
  for (int i = 0; i < N; i++) {
    printf("%02d:%02d - ", (now / 60), (now % 60));
    now += a[i];
    printf("%02d:%02d %s\n", (now / 60), (now % 60), s[i]);

    if (i == N - 1) {
      break;
    }
    if (!already && now + 10 + a[i + 1] > 12 * 60) {
      now += 60;
      already = true;
    } else {
      now += 10;
    }
  }

  return 0;

}


