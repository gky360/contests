/*
[past201912-open] H - まとめ売り / Bulk Selling
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 200000;
const int MAX_Q = 200000;
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

int N;
int C[MAX_N];
int Q;
int OP[MAX_Q], X[MAX_Q], A[MAX_Q];

int get_id(int n) { return n / 2 + (n & 1) * ((N + 1) / 2); }

ll solve() {
    LazyRMQ<int> rmq(N);
    for (int i = 0; i < N; i++) {
        int ii = get_id(i);
        rmq.add(ii, ii + 1, C[i]);
    }

    ll ans = 0;
    for (int q = 0; q < Q; q++) {
        switch (OP[q]) {
            case 1: {
                int x = X[q], a = A[q];
                int xi = get_id(x);
                if (rmq.query(xi, xi + 1) >= a) {
                    rmq.add(xi, xi + 1, -a);
                    ans += a;
                }
                break;
            }
            case 2: {
                int a = A[q];
                int mi = (N + 1) / 2;
                if (rmq.query(0, mi) >= a) {
                    rmq.add(0, mi, -a);
                    ans += 1LL * ((N + 1) / 2) * a;
                }
                break;
            }
            case 3: {
                int a = A[q];
                if (rmq.query(0, N) >= a) {
                    rmq.add(0, N, -a);
                    ans += 1LL * N * a;
                }
                break;
            }
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        cin >> OP[q];
        if (OP[q] == 1) {
            cin >> X[q] >> A[q];
            X[q]--;
        } else {
            cin >> A[q];
        }
    }

    cout << solve() << endl;

    return 0;
}
