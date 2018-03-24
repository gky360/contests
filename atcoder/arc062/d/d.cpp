// AtCoder Regular Contest 062
// D - AtCoDeerくんと変なじゃんけん / AtCoDeer and Rock-Paper

#include <cstdio>
#include <cstring>
#define MAX_N 100000
using namespace std;


int N;
char s[MAX_N + 2];
int ans;

int main() {

  scanf("%s", s);
  N = strlen(s);
  ans = 0;
  for (int i = 0; i < N; i++) {
    ans += (i % 2) - (s[i] == 'g' ? 0 : 1);
  }
  printf("%d\n", ans);

  return 0;

}


