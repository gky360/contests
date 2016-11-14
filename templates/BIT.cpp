// BIT.cpp
// BinaryIndexedTree
// int型 注意：添字1から

#include <cstdio>
#define MAX_BIT_IDX 1000000
using namespace std;


template <typename T>
class BIT {
public:
  T b[MAX_BIT_IDX + 1];
  int n;
  void init(int num);
  T sum(int i);
  void add(int i, T x);
};

template <typename T>
void BIT<T>::init(int num) {
  n = num;
  for (int i = 0; i <= n; i++) {
    b[i] = 0;
  }
  return;
}

template <typename T>
T BIT<T>::sum(int i) {
  T s = 0;

  for (; i > 0; i -= i & -i) {
    s += b[i];
  }
  return s;
}

template <typename T>
void BIT<T>::add(int i, T x) {
  for (; i <= n; i += i & -i) {
    b[i] += x;
  }
  return;
}


BIT<int> bit;

int main(){


  return 0;

}


