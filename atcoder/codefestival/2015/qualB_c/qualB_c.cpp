// CODE FESTIVAL 2015 予選B C - 旅館/Hotel

#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

#define MAX_N 100000
#define MAX_M 100000


int N, M;
int a[MAX_N];
int b[MAX_M];

int main() {

  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < M; i++) {
    scanf("%d", &b[i]);
  }

  if (N < M) {
    printf("NO\n");
    return 0;
  }

  sort(a, a + N, greater<int>());
  sort(b, b + M, greater<int>());
  for (int i = 0; i < M; i++) {
    if (a[i] < b[i]) {
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");

  return 0;

}


