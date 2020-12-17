/*
[abc164] D - Multiple of 2019
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

string S;

ll solve() {
    int N = S.length();
    reverse(ALL(S));
    vector<int> cnt(2019);
    cnt[0] = 1;
    int d = 0, p = 1;
    REP(i, N) {
        d += (S[i] - '0') * p;
        d %= 2019;
        cnt[d]++;
        p *= 10;
        p %= 2019;
    }

    ll ans = 0;
    for (int c : cnt) {
        ans += c * (c - 1) / 2;
    }
    return ans;
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
