/*
[abc171] E - Red Scarf
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

const int MAX_N = 200000;

int N;
int a[MAX_N];

void solve() {
    int s = 0;
    REP(i, N) s ^= a[i];
    REP(i, N) cout << (s ^ a[i]) << " ";
    cout << endl;
}

int main() {
    cin >> N;
    REP(i, N) cin >> a[i];

    solve();

    return 0;
}
