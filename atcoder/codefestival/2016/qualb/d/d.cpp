// CODE FESTIVAL 2016 qual B
// D - Greedy customers

#include <cstdio>
using namespace std;

typedef long long int ll;


int N;
int min_p;
ll ans;

int main() {

  int a;

  scanf("%d", &N);
  min_p = 0;
  ans = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &a);
    ans += (a - 1) / (min_p + 1);
    if (a == min_p + 1 || i == 0) {
      min_p++;
    }
  }
  printf("%lld\n", ans);

  return 0;

}


