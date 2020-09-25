/*
[abc154] B - I miss you...
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S;

string solve() { return string(S.size(), 'x'); }

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
