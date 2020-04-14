/*
[abc139] B - Power Socket
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int A, B;

ll solve() { return (B + A - 3) / (A - 1); }

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
