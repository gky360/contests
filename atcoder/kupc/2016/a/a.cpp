// Kyoto University Programming Contest 2016
// A - バリケード / A Barricade

#include <cstdio>
using namespace std;


int N, A, B;
int ans;

int main() {

  int t;

  scanf("%d%d%d", &N, &A, &B);
  ans = N;
  for (int i = 0; i < N; i++) {
    scanf("%d", &t);
    if (A <= t && t < B) {
      ans--;
    }
  }

  printf("%d\n", ans);

  return 0;

}


