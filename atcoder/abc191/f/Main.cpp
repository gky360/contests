/*
[abc191] F - GCD or MIN
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

const int MAX_N = 2000;

int N;
ll A[MAX_N];

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

vector<ll> divisors(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

ll solve() {
    ll ma = *min_element(A, A + N);
    unordered_map<ll, ll> m;
    REP(i, N) {
        for (ll d : divisors(A[i])) {
            m[d] = m.count(d) == 0 ? A[i] : gcd(m[d], A[i]);
        }
    }

    ll ans = 0;
    for (auto [k, v] : m) {
        if (k <= ma && k == v) ans++;
    }

    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
