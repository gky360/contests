// CODE FESTIVAL 2016 qual C
// A - CF

#include <cstdio>
#include <cstring>
#define MAX_S 100
using namespace std;


char s[MAX_S + 1];
bool is_c;

int main() {

  scanf("%s", s);
  for (int i = 0; i < (int)strlen(s); i++) {
    if (s[i] == 'C') {
      is_c = true;
    } else if(is_c && s[i] == 'F') {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");

  return 0;

}


