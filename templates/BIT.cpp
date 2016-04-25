//BIT.cpp
//BinaryIndexedTree
//int型 注意：添字1から

#include <cstdio>
#define NMAX 1000000
using namespace std;


class BIT {
public:
  int bit[MAX_N + 1];
  int n;
private:
public:
  void init(int num);
  int sum(int i);
  void add(int i, int x);
private:
};

void BIT::init(int num) {
  n = num;
  for (int i = 0; i <= n; i++) {
    bit[i] = 0;
  }
  return;
}

int BIT::sum(int i) {
  int s = 0;

  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void BIT::add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
  return;
}


int main(){


  return 0;

}


