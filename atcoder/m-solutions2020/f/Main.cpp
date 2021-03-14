/*
[m-solutions2020] F - Air Safety
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
const int MAX_X = 200000;
const int INF = 1e7;

int N;
int X[MAX_N], Y[MAX_N], U[MAX_N];
vector<int> ls[MAX_X + 1], rs[2 * MAX_X + 1], us[2 * MAX_X + 1];
string urdl = "URDL";

pii rot(pii xy, int d) {
    int x = xy.first, y = xy.second;
    switch (d) {
        case 1:
            return {y, MAX_X - x};
        case 2:
            return {MAX_X - x, MAX_X - y};
        case 3:
            return {MAX_X - y, x};
        default:
            return {x, y};
    }
}

ll calc(int k) {
    int ret = INF;

    REP(j, MAX_X + 1) ls[j].clear(), rs[j].clear();
    REP(i, N) {
        int z = (U[i] + k) % 4;
        pii xy = rot({X[i], Y[i]}, k);
        if (z == 1) {
            rs[xy.second].push_back(xy.first);
        } else if (z == 3) {
            ls[xy.second].push_back(xy.first);
        }
    }
    REP(j, MAX_X + 1) {
        sort(ALL(ls[j]));
        for (int x : rs[j]) {
            auto iter = lower_bound(ALL(ls[j]), x);
            if (iter != ls[j].end()) {
                ret = min(ret, (*iter - x) * 5);
            }
        }
    }

    REP(j, MAX_X * 2 + 1) rs[j].clear(), us[j].clear();
    REP(i, N) {
        int z = (U[i] + k) % 4;
        pii xy = rot({X[i], Y[i]}, k);
        if (z == 0) {
            us[xy.first + xy.second].push_back(xy.first);
        } else if (z == 1) {
            rs[xy.first + xy.second].push_back(xy.first);
        }
    }
    REP(j, MAX_X * 2 + 1) {
        sort(ALL(us[j]));
        for (int x : rs[j]) {
            auto iter = lower_bound(ALL(us[j]), x);
            if (iter != us[j].end()) {
                ret = min(ret, (*iter - x) * 10);
            }
        }
    }

    return ret;
}

ll solve() {
    ll ans = INF;
    REP(d, 4) ans = min(ans, calc(d));
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) {
        char c;
        cin >> X[i] >> Y[i] >> c;
        U[i] = urdl.find(c);
    }

    ll ans = solve();
    if (ans == INF) {
        cout << "SAFE" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
