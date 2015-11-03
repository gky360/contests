// Paiza learning
// プログラミングスキルチェック
// D008:奇数か偶数か

#include <cstdio>
#include <algorithm>
using namespace std;


int main() {

  int N;

  scanf("%d", &N);
  printf("%s\n", (N % 2) == 0 ? "even" : "odd");

  return 0;

}


