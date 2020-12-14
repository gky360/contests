/*
[abc164] B - Battle
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

bool solve() { return (A + D - 1) / D >= (C + B - 1) / B; }

int main() {
    cin >> A >> B >> C >> D;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
