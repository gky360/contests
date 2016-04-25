// AtCoder Indeedなう（オープンコンテストB）
// B - How are you?

#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;


int N;
int S[MAX_N], T[MAX_N];

int main() {

  int sorted[MAX_N];

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &S[i], &T[i]);
    sorted[i] = S[i];
  }
  sort(sorted, sorted + N);

  for (int i = 0; i < N; i++) {
    printf("%ld\n", lower_bound(sorted, sorted + N, T[i]) - lower_bound(sorted, sorted + N, S[i]) - 1);
  }

  return 0;

}


