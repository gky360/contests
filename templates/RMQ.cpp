// RMQ

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int INF = 1e9;

template <typename T>
class LazyRMQ {
public:
    int n;
    vector<T> data;
    vector<T> lazy;
    LazyRMQ(int _n) {
        n = 1;
        while (n < _n) {
            n <<= 1;
        }
        data.resize(2 * n - 1);
        lazy.resize(2 * n - 1);
    }
    void add(int a, int b, T x) { add(a, b, x, 0, 0, n); }
    T query(int a, int b) { return query(a, b, 0, 0, n); }

private:
    void eval(int k) {
        if (lazy[k] == 0) {
            return;
        }
        data[k] += lazy[k];
        if (2 * k + 2 < 2 * n - 1) {
            lazy[2 * k + 1] += lazy[k];
            lazy[2 * k + 2] += lazy[k];
        }
        lazy[k] = 0;
    }
    void add(int a, int b, T x, int k, int l, int r) {  // [a, b), [l, r)
        eval(k);
        if (r <= a || b <= l) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[k] += x;
            eval(k);
            return;
        }
        add(a, b, x, 2 * k + 1, l, (l + r) / 2);
        add(a, b, x, 2 * k + 2, (l + r) / 2, r);
        data[k] = min(data[2 * k + 1], data[2 * k + 2]);
    }
    T query(int a, int b, int k, int l, int r) {  // [a, b), [l, r)
        eval(k);
        if (r <= a || b <= l) {
            return INF;
        }
        if (a <= l && r <= b) {
            return data[k];
        }
        return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
                   query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

template <typename T>
class RMQ {
public:
    int n;
    vector<T> data;
    RMQ(int _n) {
        n = 1;
        while (n < _n) {
            n <<= 1;
        }
        data.resize(2 * n - 1);
        fill(data.begin(), data.end(), INF);
    }
    void update(int k, T a) {
        k += n - 1;
        data[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = min(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); }

private:
    T query(int a, int b, int k, int l, int r) {  // [a, b), [l, r)
        if (r <= a || b <= l) {
            return INF;
        }
        if (a <= l && r <= b) {
            return data[k];
        }
        return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
                   query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

int main() { return 0; }
