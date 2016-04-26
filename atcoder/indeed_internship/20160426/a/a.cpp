// AtCoder Indeed internship 2016 0426
// A - 改行

#include <cstdio>
#include <cstring>
#define MAX_N 100
using namespace std;


char S[MAX_N + 1];

int main() {

  int n;

  scanf("%s", S);
  n = strlen(S);
  for (int i = 0; i < n; i++) {
    if (S[i] == ',') {
      S[i] = '\n';
    }
  }

  printf("%s", S);

  return 0;

}


