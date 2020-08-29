/*
[abc151] C - Welcome to AtCoder
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100000;
const int MAX_M = 100000;

int N, M;
int p[MAX_M];
string S[MAX_M];
int wa[MAX_N];

pii solve() {
    pii ans = {0, 0};
    for (int i = 0; i < M; i++) {
        if (S[i] == "AC") {
            if (wa[p[i]] >= 0) {
                ans.first++;
                ans.second += wa[p[i]];
            }
            wa[p[i]] = -1;
        } else {
            if (wa[p[i]] >= 0) {
                wa[p[i]]++;
            }
        }
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> p[i] >> S[i];
        p[i]--;
    }

    pii ans = solve();
    cout << ans.first << " " << ans.second << endl;

    return 0;
}
