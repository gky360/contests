/*
[abc167] B - Easy Linear Programming
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

int A, B, C, K;

ll solve() {
    ll ans = min(K, A) - max(K - A - B, 0);
    return ans;
}

int main() {
    cin >> A >> B >> C >> K;

    cout << solve() << endl;

    return 0;
}
