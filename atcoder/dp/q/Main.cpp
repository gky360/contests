/*
[dp] Q - Flowers
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 2e5;
const ll INF = 1e18;

template <typename T>
class RMQ {
public:
    int n;
    vector<T> dat;
    void init(int _n);
    void update(int k, T a);
    T query(int a, int b);

private:
    T query(int a, int b, int k, int l, int r);
};

template <typename T>
void RMQ<T>::init(int _n) {
    n = 1;
    while (n < _n) {
        n <<= 1;
    }
    dat.reserve(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) {
        dat[i] = INF;
    }
    return;
}

template <typename T>
void RMQ<T>::update(int k, T a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
    return;
}

template <typename T>
T RMQ<T>::query(int a, int b) {
    return query(a, b, 0, 0, n);
}

// [a, b), [l, r)
template <typename T>
T RMQ<T>::query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
        return INF;
    }
    if (a <= l && r <= b) {
        return dat[k];
    }
    return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
               query(a, b, k * 2 + 2, (l + r) / 2, r));
}

int N;
int h[MAX_N], a[MAX_N];
RMQ<ll> t;

ll solve() {
    t.init(N + 1);
    t.update(0, 0);

    for (int i = 0; i < N; i++) {
        ll m = t.query(0, h[i]);
        t.update(h[i], m - a[i]);
    }

    return -t.query(0, N + 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
