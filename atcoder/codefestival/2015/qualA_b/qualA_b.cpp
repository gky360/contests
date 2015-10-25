// qualA_b.cpp
// CODE FESTIVAL 2015 予選A B - とても長い数列

#include <climits>
#include <cstdio>
using namespace std;

int N;

int main() {

  int sum, a;
  scanf("%d", &N);

  sum = 0;
  for (int n = 0; n < N; n++) {
    scanf("%d", &a);
    sum = sum * 2 + a;
  }

  printf("%d\n", sum);

  return 0;

}
