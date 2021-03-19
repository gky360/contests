/*
[abc174] D - Alter Altar
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

const int MAX_N = 200000;

int N;
string c;
int r[MAX_N + 1];

ll solve() {
    REP(i, N) r[i + 1] = r[i] + (c[i] == 'R' ? 1 : 0);

    int ans = N;
    REP(i, N + 1) ans = min(ans, max(i - r[i], r[N] - r[i]));
    return ans;
}

int main() {
    cin >> N;
    cin >> c;

    cout << solve() << endl;

    return 0;
}
