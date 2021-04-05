/*
[abc176] B - Multiple of 9
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

string N;

ll solve() {
    ll s = 0;
    for (char c : N) {
        s += c - '0';
        s %= 9;
    }
    return s == 0;
}

int main() {
    cin >> N;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
