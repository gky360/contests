/*
[abc152] B - Comparing Strings
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int a, b;

string solve() {
    if (a > b) swap(a, b);

    string ans(b, '0' + a);

    return ans;
}

int main() {
    cin >> a >> b;

    cout << solve() << endl;

    return 0;
}
