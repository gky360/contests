/*
[past202010-open] K - 転倒数
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_K = 1e5;
const int MAX_Q = 1e5;
const int MAX_N = 1e5;
const int MAX_A = 20;
const int MOD = 1e9;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(ll n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

int K;
int n[MAX_K];
vector<int> a[MAX_K];
int Q;
int b[MAX_Q];

pair<gf, vector<int>> check(int k) {
    vector<int> cnt(MAX_A);
    gf ret = 0;
    REP(i, n[k]) {
        for (int j = a[k][i] + 1; j < MAX_A; j++) {
            ret += cnt[j];
        }
        cnt[a[k][i]]++;
    }
    return {ret, cnt};
}

ll solve() {
    gf v[MAX_K];
    vector<int> c[MAX_K];
    REP(k, K) {
        auto x = check(k);
        v[k] = x.first, c[k] = x.second;
    }

    vector<gf> cnt(MAX_A);
    gf ans = 0;
    REP(q, Q) {
        ans += v[b[q]];
        REP(i, MAX_A) {
            REP(j, i) ans += cnt[i] * c[b[q]][j];
            cnt[i] += c[b[q]][i];
        }
    }

    return ans.n;
}

int main() {
    cin >> K;
    REP(k, K) {
        cin >> n[k];
        a[k].resize(n[k]);
        REP(i, n[k]) cin >> a[k][i], a[k][i]--;
    }
    cin >> Q;
    REP(q, Q) cin >> b[q], b[q]--;

    cout << solve() << endl;

    return 0;
}
