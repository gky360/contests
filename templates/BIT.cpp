// BIT.cpp
// BinaryIndexedTree

#include <cstdio>
using namespace std;

const int MAX_BIT_IDX = 1000000;

template <typename T>
class BIT {
public:
    T b[MAX_BIT_IDX + 1];
    int n;
    void init(int num);
    T sum(int i);          // i : [0, n), returns sum of [0, i)
    void add(int i, T x);  // i : [0, n)
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
    for (i += 1; i <= n; i += i & -i) {
        b[i] += x;
    }
    return;
}

template <typename T>
class LinearBIT {
public:
    BIT<T> bit0, bit1;
    void init(int num);
    T sum(int i);
    void add(int l, int r, T x);  // [l, r)
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

BIT<int> bit;
LinearBIT<int> rb;

int main() { return 0; }
