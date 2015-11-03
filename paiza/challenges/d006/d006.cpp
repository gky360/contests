// Paiza learning
// プログラミングスキルチェック
// D006:単位の計算

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main() {

  int n;
  char s[16];

  scanf("%d%s", &n, s);

  if (strcmp(s, "km") == 0) {
    n *= 1000 * 1000;
  } else if (strcmp(s, "m") == 0) {
    n *= 1000;
  } else {
    n *= 10;
  }
  printf("%d\n", n);

  return 0;

}


