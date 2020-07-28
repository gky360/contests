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
class RMQ {
public:
    int n;
    vector<T> dat;
    RMQ(int _n) {
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

int N;
int C[MAX_N];
int Q;
int OP[MAX_Q], X[MAX_Q], A[MAX_Q];

ll solve() {
    RMQ<int> rmq[2] = {RMQ<int>((N + 1) / 2), RMQ<int>(N / 2)};
    for (int i = 0; i < N; i++) {
        rmq[i & 1].update(i / 2, C[i]);
    }

    int s[2] = {0, 0};
    ll ans = 0;
    for (int q = 0; q < Q; q++) {
        switch (OP[q]) {
            case 1: {
                int x = X[q], a = A[q];
                int v = rmq[x & 1].query(x / 2, x / 2 + 1);
                if (v - s[x & 1] >= a) {
                    rmq[x & 1].update(x / 2, v - a);
                    ans += a;
                }
                break;
            }
            case 2: {
                int a = A[q];
                int v = rmq[0].query(0, (N + 1) / 2);
                if (v - s[0] >= a) {
                    s[0] += a;
                    ans += ((N + 1LL) / 2LL) * a;
                }
                break;
            }
            case 3: {
                int a = A[q];
                int v0 = rmq[0].query(0, (N + 1) / 2);
                int v1 = rmq[1].query(0, N / 2);
                if (v0 - s[0] >= a && v1 - s[1] >= a) {
                    s[0] += a;
                    s[1] += a;
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
