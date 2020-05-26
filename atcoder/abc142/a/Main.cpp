/*
[abc142] A - Odds of Oddness
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;

double solve() { return ((N + 1) / 2) * 1.0 / N; }

int main() {
    cin >> N;

    cout << setprecision(16) << solve() << endl;

    return 0;
}
