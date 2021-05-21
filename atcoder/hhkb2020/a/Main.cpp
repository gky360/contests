/*
[hhkb2020] A - Keyboard
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

char S, T;

char solve() {
    char ans = (S == 'Y') ? T - 32 : T;
    return ans;
}

int main() {
    cin >> S >> T;

    cout << solve() << endl;

    return 0;
}
