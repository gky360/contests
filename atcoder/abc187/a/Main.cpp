/*
[abc187] A - Large Digits
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

string A, B;

int S(string n) { return (n[0] - '0') + (n[1] - '0') + (n[2] - '0'); }

int solve() { return S(A) >= S(B) ? S(A) : S(B); }

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
