// Paiza learning
// プログラミングスキルチェック
// D003:掛け算のリスト

#include <cstdio>
#include <algorithm>
using namespace std;


int N;

int main() {

  scanf("%d", &N);
  for (int i = 1; i <= 9; i++) {
    printf("%d%c", i * N, i == 9 ? '\n' : ' ');
  }

  return 0;

}


