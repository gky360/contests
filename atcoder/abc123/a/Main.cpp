/*
[abc123] A - Five Antennas
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int a, b, c, d, e;
int k;

bool solve() { return (e - a) <= k; }

int main() {
    cin >> a >> b >> c >> d >> e;
    cin >> k;

    cout << (solve() ? "Yay!" : ":(") << endl;

    return 0;
}
