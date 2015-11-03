// Paiza learning
// プログラミングスキルチェック
// C006:ハイスコアランキング

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100
#define MAX_M 1000


int N, M, K;
double S[MAX_M], C[MAX_N];

int main() {

  int x;

  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < N; i++) {
    scanf("%lf", &C[i]);
  }
  for (int j = 0; j < M; j++) {
    S[j] = 0;
    for (int i = 0; i < N; i++) {
      scanf("%d", &x);
      S[j] += C[i] * x;
    }
  }

  sort(S, S + M);

  for (int j = 0; j < K; j++) {
    printf("%d\n", (int)(S[M - j - 1] + 0.5));
  }

  return 0;

}