// LinearBIT.cpp
// 区間に一様に値を加えられるようにした BIT
// int型 注意：添字1から

#include <cstdio>
#define MAX_BIT_IDX 100000
using namespace std;


template <typename T>
class LinearBIT {
public:
  BIT<T> bit0, bit1;
  void init(int num);
  T sum(int i);
  void add(int l, int r, T x); // [l, r)
};

template <typename T>
void LinearBIT<T>::init(int num) {
  bit0.init(num);
  bit1.init(num);
  return;
}

// [l, r)
template <typename T>
void LinearBIT<T>::add(int l, int r, T x) {
  bit0.add(l, -x * (l - 1));
  bit1.add(l, x);
  bit0.add(r, x * (r - 1));
  bit1.add(r, -x);
  return;
}

template <typename T>
T LinearBIT<T>::sum(int i) {
  return bit1.sum(i) * i + bit0.sum(i);
}


LinearBIT<ll> l_bit;

int main() {



  return 0;

}


