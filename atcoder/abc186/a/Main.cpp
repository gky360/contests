/*
[abc186] A - Brick
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

int N, W;

ll solve() {


    ll ans = N / W;
    return ans;
}

int main() {
    cin >> N >> W;


    cout << solve() << endl;

    return 0;

}
