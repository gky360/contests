// Paiza learning
// プログラミングスキルチェック
// D005:等差数列

#include <cstdio>
#include <algorithm>
using namespace std;


int M, N;

int main() {

  scanf("%d%d", &M, &N);
  for (int i = 0; i < 10; i++) {
    printf("%d%c", M + N * i, (i == 10 - 1) ? '\n' : ' ');
  }

  return 0;

}


