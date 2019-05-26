/*
[abc128] E - Roadwork
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
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
typedef pair<ll, ll> pll;

const int MAX_N = 2e5;
const int MAX_Q = 2e5;

enum EV {
    EV_T = 0,
    EV_S = 1,
    EV_D = 2,
};

int N, Q;
int S[MAX_N], T[MAX_N], X[MAX_N];
int D[MAX_Q];

void solve() {
    vector<pair<int, pair<EV, int>>> events;
    for (int i = 0; i < N; i++) {
        events.push_back({S[i] - X[i], {EV_S, X[i]}});
        events.push_back({T[i] - X[i], {EV_T, X[i]}});
    }
    for (int i = 0; i < Q; i++) {
        events.push_back({D[i], {EV_D, i}});
    }
    sort(events.begin(), events.end());

    vector<int> ans(Q);
    set<int> cur;
    for (auto& e : events) {
        switch (e.second.first) {
            case EV_T:
                cur.erase(e.second.second);
                break;
            case EV_S:
                cur.insert(e.second.second);
                break;
            default:
                ans[e.second.second] = cur.empty() ? -1 : *cur.begin();
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i] >> X[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> D[i];
    }

    solve();

    return 0;
}
