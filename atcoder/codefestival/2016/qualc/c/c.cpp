// CODE FESTIVAL 2016 qual C
// C - 二人のアルピニスト / Two Alpinists

#include <cstdio>
#include <algorithm>
#define MAX_N 100000
#define MOD 1000000007
using namespace std;

typedef long long int ll;


int N;
int T[MAX_N + 2], A[MAX_N + 2];
bool is_clear;
ll ans;

int main() {

  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &T[i]);
  }
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }
  T[0] = 0;
  A[N + 1] = 0;

  ans = 1;
  for (int i = 1; i <= N; i++) {
    is_clear = false;
    if (T[i - 1] != T[i]) {
      if (T[i] > A[i]) {
        printf("%d\n", 0);
        return 0;
      }
      is_clear = true;
    }
    if (A[i] != A[i + 1]) {
      if (A[i] > T[i]) {
        printf("%d\n", 0);
        return 0;
      }
      is_clear = true;
    }
    if (!is_clear) {
      ans = ans * min(T[i], A[i]) % MOD;
    }
  }
  printf("%lld\n", ans);

  return 0;

}


