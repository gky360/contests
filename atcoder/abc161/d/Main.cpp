/*
[abc161] D - Lunlun Number
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

int K;

ll solve() {
    queue<ll> q;
    REP(i, 9) q.push(i + 1);
    ll x = 0;
    REP(i, K) {
        x = q.front();
        q.pop();
        ll d = x % 10;
        if (d > 0) q.push(x * 10 + d - 1);
        q.push(x * 10 + x % 10);
        if (d < 9) q.push(x * 10 + d + 1);
    }
    return x;
}

int main() {
    cin >> K;

    cout << solve() << endl;

    return 0;
}
