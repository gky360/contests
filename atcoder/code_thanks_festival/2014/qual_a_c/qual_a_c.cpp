// code thanks festival 2014 予選A C - コンテスト

#include <cstdio>
using namespace std;

#define MAX_N 100


int N, M;
int P[MAX_N];
int ans;

int main() {

  int s;
  int i;

  scanf("%d%d", &N, &M);
  for (i = 0; i < N; i++) {
    scanf("%d", &P[i]);
  }
  ans = 0;
  for (i = 0; i < M; i++) {
    scanf("%d", &s);
    ans += P[s - 1];
  }

  printf("%d\n", ans);

  return 0;
}
