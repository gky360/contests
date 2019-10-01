/*
[abc123] D - Cake 123
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_X = 1000;
const ll MAX_A = 1e10;

int X[3], K;
ll A[3][MAX_X];

bool can(ll t) {
    int cnt = 0;
    for (int i = 0; i < X[0]; i++) {
        for (int j = 0; j < X[1]; j++) {
            for (int k = 0; k < X[2]; k++) {
                ll s = A[0][i] + A[1][j] + A[2][k];
                if (s < t) {
                    break;
                }
                cnt++;
                if (cnt >= K) {
                    return true;
                }
            }
        }
    }

    return false;
}

vector<ll> solve() {
    for (int i = 0; i < 3; i++) {
        sort(A[i], A[i] + X[i], greater<ll>());
    }

    ll ok = 0, ng = MAX_A * 3;
    while (ng - ok > 1) {
        ll m = (ng + ok) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    ll t = ok;
    vector<ll> ans;
    for (int i = 0; i < X[0]; i++) {
        for (int j = 0; j < X[1]; j++) {
            for (int k = 0; k < X[2]; k++) {
                ll s = A[0][i] + A[1][j] + A[2][k];
                if (s < t) {
                    break;
                }
                ans.push_back(s);
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<ll>());
    ans.resize(K);

    return ans;
}

int main() {
    cin >> X[0] >> X[1] >> X[2] >> K;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < X[j]; i++) {
            cin >> A[j][i];
        }
    }

    auto ans = solve();
    for (ll v : ans) {
        cout << v << endl;
    }

    return 0;
}
