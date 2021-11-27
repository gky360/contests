/*
[keyence2021] D - Choosing Up Sides
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

int popcount(int x) {
    int ret = 0;
    for (; x > 0; x = x >> 1)
        if (x & 1) ret++;
    return ret;
}

void solve() {
    int K = (1 << N) - 1;
    cout << K << endl;
    REP(i, K) {
        string s;
        REP(j, 1 << N) s += popcount((i + 1) & j) % 2 == 0 ? 'A' : 'B';
        cout << s << endl;
    }
}

int main() {
    cin >> N;

    solve();

    return 0;
}
