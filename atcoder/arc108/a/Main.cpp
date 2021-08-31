/*
[arc108] A - Sum and Product
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

ll S, P;

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

bool solve() {
    auto ds = divisors(P);

    for (ll d : ds) {
        if (d + P / d == S) return true;
    }

    return false;
}

int main() {
    cin >> S >> P;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
