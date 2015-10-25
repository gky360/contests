// CODE FESTIVAL 2015 予選B B - 採点/Grading

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_M 100000


int N, M;
int scores[MAX_M + 1];

int main() {

  int a;
  int *ptr;

  scanf("%d%d", &N, &M);
  memset(scores, 0, sizeof(scores));
  for (int i = 0; i < N; i++) {
    scanf("%d", &a);
    scores[a]++;
  }

  ptr = max_element(scores, scores + M + 1);
  if (*ptr > N / 2) {
    printf("%d\n", (int)(ptr - scores));
  } else {
    printf("?\n");
  }

  return 0;

}


