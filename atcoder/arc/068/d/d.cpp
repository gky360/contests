// AtCoder Regular Contest 068
// D - Card Eater

#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;
typedef long long int ll;


int N;
int A[MAX_N];
int ans;

int main() {

  int a;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  sort(A, A + N);

  a = A[0];
  ans = 1;
  for (int i = 0; i < N; i++) {
    if (A[i] != a) {
      a = A[i];
      ans += 1;
    }
  }
  ans += (ans % 2) - 1;

  printf("%d\n", ans);

  return 0;

}


