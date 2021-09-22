/*
[arc110] C - Exoswap
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

const int MAX_N = 2e5;

int N;
int P[MAX_N];
int ip[MAX_N];
vector<int> ans;

bool calc(int l) {
    if ((int)ans.size() == N - 1) {
        REP(i, N) {
            if (P[i] != i) return false;
        }
        return true;
    }
    if (ip[l] <= l) return false;
    for (int i = ip[l] - 1; i >= l; i--) {
        ans.push_back(i);
        swap(P[i], P[i + 1]);
    }
    return calc(ip[l]);
}

bool solve() {
    REP(i, N) ip[P[i]] = i;
    return calc(0);
}

int main() {
    cin >> N;
    REP(i, N) cin >> P[i], P[i]--;

    if (!solve()) {
        cout << -1 << endl;
    } else {
        REP(i, N - 1) cout << ans[i] + 1 << endl;
    }

    return 0;
}
