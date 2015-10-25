// qualA_a.cpp
// CODE FESTIVAL 2014 予選A A - CODE FESTIVAL 2014

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAX_N 20


char str[MAX_N + 4 + 1];

int main() {

  int idx;

  scanf("%s", str);
  idx = strlen(str);
  sprintf(str + idx, "2014");

  printf("%s\n", str);

  return 0;

}


