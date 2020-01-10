/*
[jag2013summer-day3] D - Fast Division
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int n;

ll solve() { return n == 0 ? 1 : n == 1 ? 2 : n == 2 ? 1 : 0; }

int main() {
    cin >> n;

    cout << solve() << endl;

    return 0;
}
