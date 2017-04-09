// AtCoder Regular Contest 071
// E - TrBBnsformBBtion

#include <cstdio>
#include <cstring>
#define P 5
#define MAX_S 100000
using namespace std;
typedef long long int ll;


char S[2][MAX_S + 2];
int L[2], sum_a[2][MAX_S + 1];
int Q;


int main() {

  int a, b, c, d;

  scanf("%s", &S[0]);
  scanf("%*c%s", &S[1]);
  for (int j = 0; j < 2; j++) {
    L[j] = strlen(S[j]);
    sum_a[j][0] = 0;
    for (int i = 1; i <= L[j]; i++) {
      sum_a[j][i] = sum_a[j][i - 1] + (S[j][i - 1] == 'A' ? 1 : 0);
    }
  }

  scanf("%d", &Q);
  for (int q = 0; q < Q; q++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if ( ((b - a + 1 - 2 * (sum_a[0][b] - sum_a[0][a - 1])) - (d - c + 1 - 2 * (sum_a[1][d] - sum_a[1][c - 1]))) % 3 == 0 ) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }


  return 0;

}

