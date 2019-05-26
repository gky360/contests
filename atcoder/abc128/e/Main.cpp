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

int N, Q;
int S[MAX_N], T[MAX_N], X[MAX_N];
int D[MAX_Q];
vector<int> cx;

void solve() {
    for (int i = 0; i < N; i++) {
        S[i] -= X[i];
        T[i] -= X[i];
        cx.push_back(S[i]);
        cx.push_back(T[i]);
    }
    for (int i = 0; i < Q; i++) {
        cx.push_back(D[i]);
    }
    sort(cx.begin(), cx.end());
    cx.erase(unique(cx.begin(), cx.end()), cx.end());

    vector<pair<pii, bool>> line;
    for (int i = 0; i < N; i++) {
        int sx = lower_bound(cx.begin(), cx.end(), S[i]) - cx.begin();
        int tx = lower_bound(cx.begin(), cx.end(), T[i]) - cx.begin();
        line.push_back({{sx, X[i]}, true});
        line.push_back({{tx, X[i]}, false});
    }
    sort(line.begin(), line.end());

    vector<int> ans(cx.size());
    set<int> cur;
    int j = 0;
    for (int i = 0; i < (int)cx.size(); i++) {
        for (; j < (int)line.size() && line[j].first.first <= i; j++) {
            if (line[j].second) {
                cur.insert(line[j].first.second);
            } else {
                cur.erase(line[j].first.second);
            }
        }
        ans[i] = cur.empty() ? -1 : *cur.begin();
    }

    for (int i = 0; i < Q; i++) {
        int cd = lower_bound(cx.begin(), cx.end(), D[i]) - cx.begin();
        cout << ans[cd] << endl;
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
