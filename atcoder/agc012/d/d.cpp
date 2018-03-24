// AtCoder Grand Contest 012
// D - Colorful Balls

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 200000;
const int MAX_C = MAX_N;
const ll INF = (ll)1e18;
const ll MOD = (ll)1e9 + 7;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

ll mod_inv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x) % m;
}

int N;
ll X, Y;
int C;
vector<ll> cw[MAX_C];
pli gl[MAX_C];
ll fact[MAX_N + 1];

int main() {

    int c;
    ll w;
    ll x_sub, y_sub, thr;
    int cnt, sum;
    ll ans;

    cin >> N >> X >> Y;
    C = 0;
    fact[0] = 1;
    for (int i = 0; i < N; i++) {
        cin >> c >> w;
        c--;
        C = max(C, c);
        cw[c].push_back(w);
        fact[i + 1] = ((i + 1) * fact[i]) % MOD;
    }
    C++;

    for (int j = 0; j < MAX_C; j++) {
        sort(cw[j].begin(), cw[j].end());
        gl[j] = pli(cw[j].empty() ? INF : cw[j][0], j);
    }
    sort(gl, gl + C);

    sum = 0;
    ans = 1;
    for (int j = 0; j < C; j++) {
        if (cw[j].empty()) {
            continue;
        }
        x_sub = X - cw[j][0];
        y_sub = (gl[0].second == j) ? Y - gl[1].first : Y - gl[0].first;
        thr = (y_sub < cw[j][0]) ? y_sub : max(x_sub, y_sub);
        cnt = upper_bound(cw[j].begin(), cw[j].end(), thr) - cw[j].begin();
        sum += cnt;
        ans = (ans * mod_inv(fact[cnt], MOD)) % MOD;
    }
    ans = (ans * fact[sum]) % MOD;

    cout << ans << endl;

    return 0;

}
