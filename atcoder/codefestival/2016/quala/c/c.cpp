// CODE FESTIVAL 2016 qual A
// C - 次のアルファベット / Next Letter

#include <cstdio>
#include <cstring>
#define MAX_S 100000
#define ALPHABETS 26
using namespace std;


char s[MAX_S + 2];
int K;

int main() {

  int len = 0;
  int n;

  scanf("%s", s);
  scanf("%d", &K);
  len = strlen(s);

  for (int i = 0; i < len; i++) {
    n = s[i] - 'a';
    if (n == 0) {
      continue;
    }
    if (K >= ALPHABETS - n) {
      K -= ALPHABETS - n;
      s[i] = 'a';
    }
  }
  if (K > 0) {
    n = s[len - 1] - 'a';
    n = (n + K) % ALPHABETS;
    s[len - 1] = n + 'a';
  }

  printf("%s\n", s);

  return 0;

}


