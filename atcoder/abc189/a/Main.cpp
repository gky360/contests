/*
[abc189] A - Slot
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

string C;

bool solve() { return C[0] == C[1] && C[1] == C[2]; }

int main() {
    cin >> C;

    cout << (solve() ? "Won" : "Lost") << endl;

    return 0;
}
