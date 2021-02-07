/*
[abc171] A - αlphabet
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

char c;

char solve() { return 'A' <= c && c <= 'Z' ? 'A' : 'a'; }

int main() {
    cin >> c;

    cout << solve() << endl;

    return 0;
}
