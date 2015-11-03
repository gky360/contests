// Paiza learning
// プログラミングスキルチェック
// D002:数の比較

#include <cstdio>
#include <algorithm>
using namespace std;


int main() {

  int a, b;

  scanf("%d%d", &a, &b);
  if (a == b) {
    printf("eq\n");
  } else {
    printf("%d\n", max(a, b));
  }

  return 0;

}


