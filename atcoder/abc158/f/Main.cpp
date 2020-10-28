/*
[abc158] F - Removing Robots
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;
const int MOD = 998244353;

template <typename T>
class RMQMax {
public:
    int n;
    vector<T> data;
    RMQMax(int _n) {
        n = 1;
        while (n < _n) n <<= 1;
        data.resize(2 * n - 1);
    }
    void update(int k, T a) {
        k += n - 1;
        data[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = max(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); }

private:
    T query(int a, int b, int k, int l, int r) {  // [a, b), [l, r)
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return data[k];
        return max(query(a, b, k * 2 + 1, l, (l + r) / 2),
                   query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

int N;
pll XD[MAX_N];
int r[MAX_N];
gf dp[MAX_N + 1];

ll solve() {
    RMQMax<int> rmq(N + 1);

    sort(XD, XD + N);

    for (int i = N - 1; i >= 0; i--) {
        int j =
            lower_bound(XD, XD + N, pll(XD[i].first + XD[i].second, 0)) - XD;
        r[i] = max(i, rmq.query(i + 1, j));
        rmq.update(i, r[i]);
    }

    dp[N] = 1;
    for (int i = N - 1; i >= 0; i--) {
        dp[i] = dp[i + 1] + dp[r[i] + 1];
    }

    ll ans = dp[0].n;
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> XD[i].first >> XD[i].second;
    }

    cout << solve() << endl;

    return 0;
}
