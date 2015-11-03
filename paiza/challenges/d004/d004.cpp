// Paiza learning
// プログラミングスキルチェック
// D004:文字列の結合

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_M 20


int N;

int main() {

  char str[MAX_M + 1];

  scanf("%d", &N);
  printf("Hello ");
  for (int i = 0; i < N; i++) {
    scanf("%s", str);
    printf("%s%s", str, i == N - 1 ? ".\n" : ",");
  }

  return 0;

}


