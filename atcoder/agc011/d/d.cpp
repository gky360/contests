// AtCoder Grand Contest 011
// D - Half Reflector

#include <cstdio>
#define MAX_N 200000
using namespace std;
typedef long long int ll;


int N;
ll K;
char ans[MAX_N + 1];

int main() {

  char c;
  int inv;

  scanf("%d%lld", &N, &K);
  scanf("%*c");
  ans[N + 1] = '\0';

  inv = 0;
  int j = 0;
  for (int i = 0; i < N; i++) {
    scanf("%c", &c);
    if ((c - 'A' + i) % 2 == 0) {
      inv++;
    }
    if ((ll)inv + i >= K) {
      ans[j] = ((c - 'A') + (i - j)) % 2 + 'A';
      if (j == 0 && K == (ll)inv + i) {
        ans[j] = 'B';
      }
      j++;
    }
  }
  if (j == 0 && N % 2 == 1) {
    ans[0] = (inv + K + 1) % 2 + 'A';
    j++;
  }
  for (; j < N; j++) {
    ans[j] = (N - j + 1) % 2 + 'A';
  }
  printf("%s\n", ans);

  return 0;

}


