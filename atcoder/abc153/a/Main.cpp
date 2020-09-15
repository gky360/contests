/*
[abc153] A - Serval vs Monster
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int H, A;

ll solve() { return (H + A - 1) / A; }

int main() {
    cin >> H >> A;

    cout << solve() << endl;

    return 0;
}
