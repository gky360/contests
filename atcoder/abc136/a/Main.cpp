/*
[abc136] A - Transfer
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int A, B, C;

ll solve() { return max(0, C - (A - B)); }

int main() {
    cin >> A >> B >> C;

    cout << solve() << endl;

    return 0;
}
