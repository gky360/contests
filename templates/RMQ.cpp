// RMQ

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int INF = 1e9;

template <typename T>
class RMQ {
public:
    int n;
    vector<T> dat;
    void init(int _n) {
        n = 1;
        while (n < _n) {
            n <<= 1;
        }
        dat.reserve(2 * n - 1);
        fill(dat.begin(), dat.end(), INF);
    }
    void update(int k, T a) {
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); }

private:
    T query(int a, int b, int k, int l, int r) {  // [a, b), [l, r)
        if (r <= a || b <= l) {
            return INF;
        }
        if (a <= l && r <= b) {
            return dat[k];
        }
        return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
                   query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

int main() { return 0; }
