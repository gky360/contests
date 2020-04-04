/*
[abc020] D - LCM Rush
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MOD = 1e9 + 7;

int N, K;

class gf {
public:
    int n;
    static gf mod_inv(int a, int m) {
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a;
            u -= t * v;
            swap(a, m);
            swap(u, v);
        }
        return gf(u);
    }
    gf() : n(0) {}
    gf(int n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf operator/(gf x) { return *this * x.inv(); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
    gf& operator/=(gf x) { return *this = (*this / x); }
    gf inv() { return mod_inv(n, MOD); }
};

vector<int> divisors(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

vector<pli> prime_factorize(ll n) {
    vector<pli> ret;
    for (ll d = 2; d * d <= n; d++) {
        if (n % d != 0) {
            continue;
        }
        int e = 0;
        while (n % d == 0) {
            n /= d;
            e++;
        }
        ret.push_back({d, e});
    }
    if (n != 1) {
        ret.push_back({n, 1});
    }
    return ret;
}

gf calc(int n, int m) {
    auto des = prime_factorize(m);
    int s = des.size();
    gf ret = 0;
    for (int bit = 0; bit < 1 << s; bit++) {
        int num = 1;
        for (int i = 0; i < s; i++) {
            if (bit >> i & 1) {
                num *= des[i].first;
            }
        }

        gf a = (n / num);
        gf b = (a * (a + 1) / 2);
        if (bitset<32>(bit).count() % 2) {
            ret -= b * num;
        } else {
            ret += b * num;
        }
    }
    return ret;
}

ll solve() {
    auto divs = divisors(K);
    gf ans = 0;
    for (int div : divs) {
        ans += calc(N / div, K / div) * K;
    }

    return ans.n;
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
