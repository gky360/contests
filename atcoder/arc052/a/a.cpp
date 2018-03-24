// AtCoder Regular Contest 052
// A - 何期生？

#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAX_S 10
using namespace std;

char S[MAX_S + 1];
int ans;

int main() {

  scanf("%s", S);

  for (int i = 0; i < strlen(S); i++) {
    if ('0' <= S[i] && S[i] <= '9') {
      ans = atoi(&S[i]);
      break;
    }
  }

  printf("%d\n", ans);

  return 0;

}


