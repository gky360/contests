/*
[abc174] C - Repsept
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
    int s = 0;
    REP(i, K + 2) {
        s = (s * 10 + 7) % K;
        if (s == 0) return i + 1;
    }

    return -1;
}

int main() {
    cin >> K;

    cout << solve() << endl;

    return 0;
}
