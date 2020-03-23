/*
[abc136] F - Enclosed Points
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 2e5;
const int MOD = 998244353;
const int MAX_BIT_IDX = MAX_N;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(const gf x) const { return gf((n + x.n) % MOD); }
    gf operator-(const gf x) const { return gf((n - x.n + MOD) % MOD); }
    gf operator*(const gf x) const { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(const gf x) { return *this = (*this + x); }
    gf& operator-=(const gf x) { return *this = (*this - x); }
    gf& operator*=(const gf x) { return *this = (*this * x); }
};

template <typename T>
class BIT {
public:
    T b[MAX_BIT_IDX + 1];
    int n;
    void init(int num) {
        n = num;
        for (int i = 0; i <= n; i++) {
            b[i] = 0;
        }
        return;
    }
    T sum(int i) {  // i : [0, n], returns sum of [0, i)
        T s = 0;
        for (; i > 0; i -= i & -i) {
            s += b[i];
        }
        return s;
    }
    void add(int i, T x) {  // i : [0, n)
        for (i += 1; i <= n; i += i & -i) {
            b[i] += x;
        }
        return;
    }
};

int N;
pii XY[MAX_N];
vector<int> xs, ys;
BIT<int> bit;
int cnt[4][MAX_N];
gf pow2[MAX_N + 1];

ll solve() {
    for (int i = 0; i < N; i++) {
        xs.push_back(XY[i].first);
        ys.push_back(XY[i].second);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    for (int i = 0; i < N; i++) {
        XY[i].first =
            lower_bound(xs.begin(), xs.end(), XY[i].first) - xs.begin();
        XY[i].second =
            lower_bound(ys.begin(), ys.end(), XY[i].second) - ys.begin();
    }

    sort(XY, XY + N);

    pow2[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }

    for (int c = 0; c < 2; c++) {
        bit.init(N);
        for (int i = (c == 0 ? 0 : N - 1); 0 <= i && i < N;
             i += (c == 0 ? 1 : -1)) {
            cnt[c * 2 + 0][i] = bit.sum(XY[i].second);
            cnt[c * 2 + 1][i] = bit.sum(N) - bit.sum(XY[i].second + 1);
            bit.add(XY[i].second, 1);
        }
    }

    gf ans;
    for (int i = 0; i < N; i++) {
        ans += pow2[N - 1];
        ans += (pow2[cnt[0][i]] - 1) * (pow2[cnt[1][i]]) * (pow2[cnt[2][i]]) *
               (pow2[cnt[3][i]] - 1);
        ans += (pow2[cnt[0][i]]) * (pow2[cnt[1][i]] - 1) *
               (pow2[cnt[2][i]] - 1) * (pow2[cnt[3][i]]);
        ans -= (pow2[cnt[0][i]] - 1) * (pow2[cnt[1][i]] - 1) *
               (pow2[cnt[2][i]] - 1) * (pow2[cnt[3][i]] - 1);
    }

    return ans.n;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> XY[i].first >> XY[i].second;
    }

    cout << solve() << endl;

    return 0;
}
