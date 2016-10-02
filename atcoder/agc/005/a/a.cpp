// AtCoder Grand Contest 005
// A - STring

#include <cstdio>
#include <cstring>
#define MAX_X 200000
using namespace std;

typedef long long int ll;


char x[MAX_X + 2];
int ans;

int main() {

  int len, h;

  scanf("%s", x);
  len = strlen(x);

  ans = 0;
  h = 0;
  for (int i = 0; i < len; i++) {
    if (h <= 0 && x[i] == 'T') {
      ans++;
    } else {
      h += (x[i] == 'T') ? -1 : 1;
    }
  }

  ans *= 2;
  printf("%d\n", ans);

  return 0;

}


