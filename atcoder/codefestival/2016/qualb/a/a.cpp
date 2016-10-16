// CODE FESTIVAL 2016 qual B
// A - Signboard

#include <cstdio>
#include <cstring>
using namespace std;


char buff[256];
char correct[256] = "CODEFESTIVAL2016";
int ans;

int main() {

  scanf("%s", buff);
  ans = 0;
  for (int i = 0; i < (int)strlen(buff); i++) {
    if (buff[i] != correct[i]) {
      ans++;
    }
  }
  printf("%d\n", ans);

  return 0;

}


