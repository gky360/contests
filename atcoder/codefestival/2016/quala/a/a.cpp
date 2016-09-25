// CODE FESTIVAL 2016 qual A
// A - CODEFESTIVAL 2016

#include <cstdio>
#include <string>
using namespace std;


char s[256];

int main() {

  scanf("%s", s);
  string str(s);

  str.insert(4, " ");

  printf("%s\n", str.c_str());

  return 0;

}


