/*
[arc105] A - Fourtune Cookies
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

int A, B, C, D;

ll solve() {
    vector<int> x = {A, B, C, D, A + B, A + C, A + D, B + C, B + D, C + D};
    for (int p : x) {
        if (2 * p == A + B + C + D) return true;
    }

    return false;
}

int main() {
    cin >> A >> B >> C >> D;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
