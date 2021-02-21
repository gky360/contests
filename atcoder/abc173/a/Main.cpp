/*
[abc173] A - Payment
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

const int Y = 1000;

int N;

ll solve() {
    ll ans = (N + Y - 1) / Y * Y - N;
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
