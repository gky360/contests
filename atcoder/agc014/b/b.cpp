// AtCoder Grand Contest 014
// B - Unplanned Queries

#include <cstdio>
#include <cstring>
#define MAX_N 100000
using namespace std;
typedef long long int ll;


int N, M;
int appear[MAX_N];

int main() {

  int a;

  scanf("%d%d", &N, &M);
  memset(appear, 0, sizeof(appear));
  for (int i = 0; i < 2 * M; i++) {
    scanf("%d", &a);
    appear[a - 1]++;
  }

  for (int i = 0; i < N; i++) {
    if (appear[i] % 2 != 0) {
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");
  return 0;

  return 0;

}


