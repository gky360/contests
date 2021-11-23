/*
[keyence2021] B - Mex Boxes
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

const int MAX_N = 3e5;

int N, K;
int a[MAX_N];

ll solve() {
    unordered_map<int, int> m;
    REP(i, N) m[a[i]]++;

    int c = K;
    ll ans = 0;
    REP(i, N) {
        ans += i * max(0, c - m[i]);
        c = min(c, m[i]);
    }

    return ans;
}

int main() {
    cin >> N >> K;
    REP(i, N) cin >> a[i];

    cout << solve() << endl;

    return 0;
}
