/*
[abc126] F - XOR Matching
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int M, K;

vector<int> solve() {
    if (K >= 1 << M) {
        return {};
    }
    if (M == 0) {
        return {0, 0};
    }
    if (M == 1) {
        if (K == 0) {
            return {0, 0, 1, 1};
        }
        return {};
    }

    vector<int> ans;
    for (int i = 0; i < 1 << M; i++) {
        if (i == K) {
            continue;
        }
        ans.push_back(i);
    }
    ans.push_back(K);
    for (int i = (1 << M) - 1; i >= 0; i--) {
        if (i == K) {
            continue;
        }
        ans.push_back(i);
    }
    ans.push_back(K);

    return ans;
}

int main() {
    cin >> M >> K;

    auto ans = solve();
    if (ans.empty()) {
        cout << -1 << endl;
        return 0;
    }
    for (int n : ans) {
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}
