/*
[abc156] C - Rally
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;
const int MAX_X = 100;
const ll INF = 1e18;

int N;
int X[MAX_N];

ll calc(int p) {
    ll s = 0;
    for (int i = 0; i < N; i++) {
        s += (X[i] - p) * (X[i] - p);
    }
    return s;
}

ll solve() {
    ll ans = INF;
    for (int i = 0; i <= MAX_X; i++) {
        ans = min(ans, calc(i));
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    cout << solve() << endl;

    return 0;
}
