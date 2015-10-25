// qualA_a.cpp
// CODE FESTIVAL 2014 予選A C - 2月29日

#include <cstdio>
#include <algorithm>
using namespace std;


int A, B;

int uru_years(int n) {
  return n / 4 - n / 100 + n / 400;
}

int main() {

  scanf("%d%d", &A, &B);
  printf("%d\n", uru_years(B) - uru_years(A - 1));

  return 0;

}


