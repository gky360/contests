/*
[abc181] A - Heavy Rotation
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

int N;

string solve() { return N % 2 == 0 ? "White" : "Black"; }

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
