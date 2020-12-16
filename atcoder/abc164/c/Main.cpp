/*
[abc164] C - gacha
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
string S[MAX_N];

ll solve() {
    set<string> s;
    REP(i, N) s.insert(S[i]);

    ll ans = s.size();
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> S[i];

    cout << solve() << endl;

    return 0;
}
