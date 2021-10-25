/*
[abc187] B - Gentle Pairs
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

const int MAX_N = 1000;

int N;
int x[MAX_N], y[MAX_N];

ll solve() {
    ll ans = 0;
    REP(i, N) for (int j = i + 1; j < N; j++) {
        if (x[i] - x[j] != 0 && abs(x[i] - x[j]) >= abs(y[i] - y[j])) ans++;
    }

    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> x[i] >> y[i];

    cout << solve() << endl;

    return 0;
}
