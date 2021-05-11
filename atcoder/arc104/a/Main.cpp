/*
[arc104] A - Plus Minus
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int A, B;

void solve() { cout << (A + B) / 2 << " " << (A - B) / 2 << endl; }

int main() {
    cin >> A >> B;

    solve();

    return 0;
}
