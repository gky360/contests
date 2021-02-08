/*
[abc171] B - Mix Juice
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

int N, K;
int p[MAX_N];

ll solve() {
    sort(p, p + N);

    ll ans = accumulate(p, p + K, 0);
    return ans;
}

int main() {
    cin >> N >> K;
    REP(i, N) cin >> p[i];

    cout << solve() << endl;

    return 0;
}
