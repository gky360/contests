/*
[abc153] F - Silver Fox vs Monster
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N, D, A;
pii XH[MAX_N];
ll s[MAX_N];

ll solve() {
    sort(XH, XH + N);

    ll ans = 0;
    for (int l = 0, r = 0; l < N; l++) {
        if (l - 1 >= 0) {
            s[l] += s[l - 1];
        }
        while (r < N && XH[r].first <= XH[l].first + 2 * D) r++;
        ll c = (max(0LL, XH[l].second - s[l]) + A - 1) / A;
        ans += c;
        s[l] += c * A;
        s[r] -= c * A;
    }

    return ans;
}

int main() {
    cin >> N >> D >> A;
    for (int i = 0; i < N; i++) {
        cin >> XH[i].first >> XH[i].second;
    }

    cout << solve() << endl;

    return 0;
}
