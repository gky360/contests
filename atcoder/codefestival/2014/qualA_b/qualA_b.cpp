// qualA_a.cpp
// CODE FESTIVAL 2014 予選A B - とても長い文字列

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAX_A 50


char str[MAX_A + 1];
int B;
char ans;

int main() {

  scanf("%s", str);
  scanf("%d", &B);

  ans = str[(B - 1) % strlen(str)];

  printf("%c\n", ans);

  return 0;

}


