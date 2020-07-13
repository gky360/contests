/*
[sumitrust2019] E - Colorful Hats 2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100000;
const int MOD = 1e9 + 7;

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
int A[MAX_N];
int cnt[MAX_N + 1];

ll solve() {
    gf ans = 1;
    cnt[0] = 3;
    for (int i = 0; i < N; i++) {
        ans *= max(0, cnt[A[i]] - cnt[A[i] + 1]);
        cnt[A[i] + 1]++;
    }

    return ans.n;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
