/*
[abc173] E - Multiplication 4
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

const int MAX_N = 2e5;
const int MOD = 1e9 + 7;

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

int N, K;
ll A[MAX_N];

ll solve() {
    vector<ll> pos, neg;
    REP(i, N) {
        if (A[i] >= 0) {
            pos.push_back(A[i]);
        } else {
            neg.push_back(A[i]);
        }
    }
    sort(ALL(pos), greater<ll>());
    sort(ALL(neg));

    if (pos.size() == 0 && K % 2 == 1) {
        gf ans = 1;
        REP(i, K) ans *= neg[neg.size() - 1 - i];
        return ans.n;
    }

    int i = 0, j = 0;
    REP(k, K) {
        if (i >= (int)pos.size())
            j++;
        else if (j >= (int)neg.size())
            i++;
        else if (pos[i] >= -neg[j])
            i++;
        else
            j++;
    }

    if (j % 2 == 1) {
        if (0 < i && i < (int)pos.size() && 0 < j && j < (int)neg.size()) {
            if (neg[j - 1] * neg[j] <= pos[i - 1] * pos[i])
                i++, j--;
            else
                i--, j++;
        } else if (i > 0 && j < (int)neg.size())
            i--, j++;
        else if (j > 0 && i < (int)pos.size())
            i++, j--;
    }

    gf ans = 1;
    REP(p, i) ans *= pos[p];
    REP(n, j) ans *= neg[n];
    return ans.n;
}

int main() {
    cin >> N >> K;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
