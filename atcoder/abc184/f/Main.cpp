/*
[abc184] F - Programming Contest
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

const int MAX_N = 40;

int N;
ll T;
ll A[MAX_N];

ll solve() {
    if (N % 2 == 1) N++;
    int P = N / 2;
    vector<ll> v[2];
    REP(k, 2) {
        REP(p, 1 << P) {
            ll s = 0;
            REP(i, P) {
                if ((p >> i) & 1) s += A[i + k * P];
            }
            v[k].push_back(s);
        }
    }
    sort(ALL(v[0])), sort(ALL(v[1]));

    ll ans = 0;
    int j = (1 << P) - 1;
    REP(i, 1 << P) {
        while (j > 0 && v[0][i] + v[1][j] > T) j--;
        if (v[0][i] + v[1][j] <= T) {
            ans = max(ans, v[0][i] + v[1][j]);
        }
    }

    return ans;
}

int main() {
    cin >> N >> T;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
