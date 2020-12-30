/*
[abc166] D - I hate Factorization
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const ll INF = 1e9;

int X;

void solve() {
    for (ll a = -120; a <= 120; a++) {
        for (ll b = -120; b <= 120; b++) {
            if (a * a * a * a * a - b * b * b * b * b == X) {
                cout << a << " " << b << endl;
                return;
            }
        }
    }
}

int main() {
    cin >> X;

    solve();

    return 0;
}
