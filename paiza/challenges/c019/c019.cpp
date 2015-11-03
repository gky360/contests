// Paiza learning
// プログラミングスキルチェック
// C019:完全数とほぼ完全数

#include <cstdio>
#include <algorithm>
using namespace std;


int Q;

int main() {

  int n, sum;

  scanf("%d", &Q);
  for(int k = 0; k < Q; k++) {
    scanf("%d", &n);

    sum = 0;
    for (int i = 1; i <= n / 2; i++) {
      if (n % i == 0) {
        sum += i;
      }
    }
    if (sum == n) {
      printf("perfect\n");
    } else if (sum == n - 1) {
      printf("nearly\n");
    } else {
      printf("neither\n");
    }
  }

  return 0;

}


