/*
[abc162] A - Lucky 7
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

int N;

bool solve() {
    while (N > 0) {
        if (N % 10 == 7) return true;
        N /= 10;
    }

    return false;
}

int main() {
    cin >> N;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
