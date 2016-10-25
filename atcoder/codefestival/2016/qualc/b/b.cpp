// CODE FESTIVAL 2016 qual C
// B - K個のケーキ / K Cakes

#include <cstdio>
#include <algorithm>
using namespace std;


int K, T;

int main() {

  int a, max_a;

  scanf("%d%d", &K, &T);
  max_a = 0;
  for (int i = 0; i < T; i++) {
    scanf("%d", &a);
    max_a = max(max_a, a);
  }

  printf("%d\n", max(max_a - (K - max_a) - 1, 0));

  return 0;

}


