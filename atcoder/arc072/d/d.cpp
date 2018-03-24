// AtCoder Regular Contest 072
// D - Alice&Brown

#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int ll;


int X, Y;

int main() {

  scanf("%d%d", &X, &Y);
  printf("%s\n", abs(X - Y) <= 1 ? "Brown" : "Alice");

  return 0;

}


