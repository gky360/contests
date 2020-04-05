// BIT.cpp
// BinaryIndexedTree

#include <vector>
using namespace std;

template <typename T>
class BIT {
public:
    vector<T> b;
    BIT(int n) : b(n + 1) {}
    T sum(int i) {  // i : [0, n], returns sum of [0, i)
        T s = 0;
        for (; i > 0; i -= i & -i) {
            s += b[i];
        }
        return s;
    }
    void add(int i, T x) {  // i : [0, n)
        for (i += 1; i < (int)b.size(); i += i & -i) {
            b[i] += x;
        }
        return;
    }
};

template <typename T>
class LinearBIT {
public:
    BIT<T> bit0, bit1;
    LinearBIT(int n) : bit0(n), bit1(n) {}
    T sum(int i) { return bit1.sum(i) * i + bit0.sum(i); }
    void add(int l, int r, T x) {  // [l, r)
        bit0.add(l, -x * (l - 1));
        bit1.add(l, x);
        bit0.add(r, x * (r - 1));
        bit1.add(r, -x);
        return;
    }
};

BIT<int> bit(100000);
LinearBIT<int> lb(100000);

int main() { return 0; }
