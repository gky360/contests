/*
[m-solutions2020] A - Kyu in AtCoder
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

int X;

ll solve() {
    if (X < 600) return 8;
    if (X < 800) return 7;
    if (X < 1000) return 6;
    if (X < 1200) return 5;
    if (X < 1400) return 4;
    if (X < 1600) return 3;
    if (X < 1800) return 2;
    return 1;
}

int main() {
    cin >> X;

    cout << solve() << endl;

    return 0;
}
