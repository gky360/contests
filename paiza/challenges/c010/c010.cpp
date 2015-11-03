// Paiza learning
// プログラミングスキルチェック
// C010:安息の地を求めて

#include <cstdio>
#include <algorithm>
using namespace std;


int A, B, R, N;

int main() {

  int x, y;

  scanf("%d%d%d%d", &A, &B, &R, &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &x, &y);
    if ((x - A) * (x - A) + (y - B) * (y - B) >= R * R) {
      printf("silent\n");
    } else {
      printf("noisy\n");
    }
  }

  return 0;

}