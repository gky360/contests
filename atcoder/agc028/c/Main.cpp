/*
[agc028] C - Min Cost Cycle
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;
const ll INF = 1e18;

int N;
ll AB[MAX_N][2];

ll solve() {
    vector<pii> ab;
    bool used[MAX_N][2];

    ll ans = INF;
    for (int j = 0; j < 2; j++) {
        ll sab = 0;
        for (int i = 0; i < N; i++) {
            sab += AB[i][j];
        }
        ans = min(ans, sab);
    }

    for (int i = 0; i < N; i++) {
        ab.push_back(pii(i, 0));
        ab.push_back(pii(i, 1));
    }
    sort(ab.begin(), ab.end(), [](pii &p1, pii &p2) {
        return AB[p1.first][p1.second] < AB[p2.first][p2.second];
    });

    memset(used, 0, sizeof(used));
    ll sn = 0;
    bool has_btoa = false;
    for (int i = 0; i < N; i++) {
        used[ab[i].first][ab[i].second] = true;
        sn += AB[ab[i].first][ab[i].second];
        if (used[ab[i].first][1 - ab[i].second]) {
            has_btoa = true;
        }
    }

    if (has_btoa) {
        ans = min(ans, sn);
    } else {
        for (int x = 0; x < N; x++) {
            int j = used[x][1] ? 0 : 1;
            pii &p = (ab[N - 1].first == x) ? ab[N - 2] : ab[N - 1];
            ans = min(ans, sn + AB[x][j] - AB[p.first][p.second]);
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> AB[i][0] >> AB[i][1];
    }

    cout << solve() << endl;

    return 0;
}
