/*
[panasonic2020] C - Sqrt Inequality
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

DD EPS = 1e-14;

DD a, b, c;

bool solve() { return sqrt(a) + sqrt(b) + EPS <= sqrt(c); }

int main() {
    cin >> a >> b >> c;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
