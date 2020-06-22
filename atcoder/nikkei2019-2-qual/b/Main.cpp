/*
[nikkei2019-2-qual] B - Counting of Trees
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MOD = 998244353;

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
int D[MAX_N];
int cnt[MAX_N];

ll solve() {
    for (int i = 0; i < N; i++) {
        cnt[D[i]]++;
    }

    if (D[0] != 0) {
        return 0;
    }
    gf ans = 1;
    for (int i = 1; i < N; i++) {
        if (D[i] == 0) {
            return 0;
        }
        ans *= cnt[D[i] - 1];
    }

    return ans.n;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    cout << solve() << endl;

    return 0;
}
