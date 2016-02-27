#include <cstdio>
#include <string>
using namespace std;

char C;
string rights = "OPKL";

int main() {

  scanf("%c", &C);
  printf("%s\n", (int)rights.find(C) >= 0 ? "Right" : "Left");

  return 0;
}

