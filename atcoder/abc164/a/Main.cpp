/*
[abc164] A - Sheep and Wolves
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

int S, W;

string solve() { return S <= W ? "unsafe" : "safe"; }

int main() {
    cin >> S >> W;

    cout << solve() << endl;

    return 0;
}
