/*
[agc048] B - Bracket Score
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

const int MAX_N = 1e5;

int N;
ll A[MAX_N], B[MAX_N];

ll solve() {
    ll S = 0;
    vector<ll> d[2];
    REP(i, N) {
        d[i % 2].push_back(B[i] - A[i]);
        S += A[i];
    }
    sort(ALL(d[0]), greater<ll>());
    sort(ALL(d[1]), greater<ll>());

    ll ans = S;
    REP(i, N / 2) {
        S += d[0][i] + d[1][i];
        ans = max(ans, S);
    }
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];

    cout << solve() << endl;

    return 0;
}
