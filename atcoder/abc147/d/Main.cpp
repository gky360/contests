/*
[abc147] D - Xor Sum 4
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 3e5;
const int MAX_K = 60;
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
ll A[MAX_N];
int cnt[MAX_K];

ll solve() {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < MAX_K; k++) {
            if ((A[i] >> k) & 1) {
                cnt[k]++;
            }
        }
    }

    gf pow2 = 1;
    gf ans = 0;
    for (int k = 0; k < MAX_K; k++) {
        ans += (pow2 * cnt[k]) * (N - cnt[k]);
        pow2 *= 2;
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
