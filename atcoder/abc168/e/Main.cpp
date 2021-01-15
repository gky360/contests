/*
[abc168] E - ∙ (Bullet)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;
const int MOD = 1000000007;
const double INF = 2e18;
const double EPS = 1e-10;

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
ll A[MAX_N], B[MAX_N];

ll gcd(ll a, ll b) {
    a = abs(a), b = abs(b);
    while (b != 0) {
        swap(b, a %= b);
    }
    return a;
}

ll solve() {
    gf p2[MAX_N + 1];
    p2[0] = 1;
    for (int i = 0; i < N; i++) {
        p2[i + 1] = p2[i] * 2;
    }

    int z = 0;
    map<pii, int> m;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0 && B[i] == 0) {
            z++;
            continue;
        }
        ll g = gcd(A[i], B[i]);
        pii p = B[i] >= 0 ? pii(A[i] / g, B[i] / g) : pii(-A[i] / g, -B[i] / g);
        m[p]++;
    }

    gf ans = 1;
    while (!m.empty()) {
        auto p = *m.begin();
        pii k = p.first;
        int x = p.second;
        pii l0 = pii(-k.second, k.first), l1 = pii(k.second, -k.first);
        int y = m[l0] + m[l1];
        ans *= p2[x] + p2[y] - 1;
        m.erase(k);
        m.erase(l0);
        m.erase(l1);
    }
    ans += z - 1;

    return ans.n;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    cout << solve() << endl;

    return 0;
}
