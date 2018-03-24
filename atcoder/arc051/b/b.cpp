// AtCoder Regular Contest 051
// B - 互除法

#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_K 40
#define MAX_N 100000
using namespace std;


int K;
int f[MAX_K + 2];

int main() {

  scanf("%d", &K);

  f[0] = f[1] = 1;
  for (int i = 2; i <= K + 1; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }

  printf("%d %d\n", f[K + 1], f[K]);

  return 0;

}


