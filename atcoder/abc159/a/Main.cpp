/*
[abc159] A - The Number of Even Pairs
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

int N, M;

ll solve() {
    ll ans = N * (N - 1) / 2 + M * (M - 1) / 2;
    return ans;
}

int main() {
    cin >> N >> M;

    cout << solve() << endl;

    return 0;
}
