/*
[abc163] B - Homework
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

const int MAX_M = 1e4;

int N, M;
int A[MAX_M];

ll solve() {
    ll ans = N;
    REP(i, M) ans -= A[i];
    ans = max(ans, -1LL);
    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, M) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
