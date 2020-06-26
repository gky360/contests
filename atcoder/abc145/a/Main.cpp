/*
[abc145] A - Circle
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int R;

ll solve() { return R * R; }

int main() {
    cin >> R;

    cout << solve() << endl;

    return 0;
}
