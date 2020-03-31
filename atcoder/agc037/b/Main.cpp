/*
[agc037] B - RGB Balls
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
    gf(int n) : n(n % MOD) {}
    gf operator+(const gf x) const { return gf((n + x.n) % MOD); }
    gf operator-(const gf x) const { return gf((n - x.n + MOD) % MOD); }
    gf operator*(const gf x) const { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(const gf x) { return *this = (*this + x); }
    gf& operator-=(const gf x) { return *this = (*this - x); }
    gf& operator*=(const gf x) { return *this = (*this * x); }
};
;
int N;
string S;
int idx[MAX_N][3];

ll solve() {
    int cur[3] = {0, 0, 0};
    for (int i = 0; i < 3 * N; i++) {
        int c = S[i] == 'R' ? 0 : (S[i] == 'G' ? 1 : 2);
        idx[cur[c]++][c] = i;
    }
    for (int i = 0; i < N; i++) {
        sort(idx[i], idx[i] + 3);
    }

    gf ans = 1;
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && idx[j][0] < idx[i][1]) {
            j++;
        }
        ans *= j - i;
    }
    for (int i = N - 1, j = N - 1; i >= 0; i--) {
        while (j >= 0 && idx[i][1] < idx[j][2]) {
            j--;
        }
        ans *= i - j;
    }
    for (int i = 1; i <= N; i++) {
        ans *= i;
    }

    return ans.n;
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
