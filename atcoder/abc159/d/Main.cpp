/*
[abc159] D - Banned K
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
int A[MAX_N];
map<int, ll> cnt;

void solve() {
    REP(i, N) cnt[A[i]]++;
    ll s = 0;
    for (auto& p : cnt) {
        ll v = cnt[p.first];
        s += v * (v - 1) / 2;
    }
    REP(i, N) {
        ll v = cnt[A[i]];
        cout << s - v * (v - 1) / 2 + (v - 1) * (v - 2) / 2 << endl;
    }
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    solve();

    return 0;
}
