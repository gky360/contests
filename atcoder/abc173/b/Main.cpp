/*
[abc173] B - Judge Status Summary
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

int N;
map<string, int> cnt;

void solve() {
    string s;
    REP(i, N) {
        cin >> s;
        cnt[s]++;
    }

    for (auto t : {"AC", "WA", "TLE", "RE"}) {
        cout << t << " x " << cnt[t] << endl;
    }
}

int main() {
    cin >> N;

    solve();

    return 0;
}
