// AtCoder Beginner Contest 057
// B - Checkpoints

#include <cstdio>
#include <algorithm>
#define MAX_N 50
#define MAX_M 50
#define INF ((int)8e8)
using namespace std;
typedef long long int ll;


int N, M;
int A[MAX_N], B[MAX_N];
int C[MAX_M], D[MAX_M];

int main() {

  int l_min, l_idx, d;

  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &A[i], &B[i]);
  }
  for (int j = 0; j < M; j++) {
    scanf("%d%d", &C[j], &D[j]);
  }

  for (int i = 0; i < N; i++) {
    l_min = INF;
    l_idx = -1;
    for (int j = 0; j < M; j++) {
      d = abs(A[i] - C[j]) + abs(B[i] - D[j]);
      if (l_min > d) {
        l_min = d;
        l_idx = j + 1;
      }
    }
    printf("%d\n", l_idx);
  }

  return 0;

}


