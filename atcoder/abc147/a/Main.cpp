/*
[abc147] A - Blackjack
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int A[3];

bool solve() { return A[0] + A[1] + A[2] <= 21; }

int main() {
    cin >> A[0] >> A[1] >> A[2];

    cout << (solve() ? "win" : "bust") << endl;

    return 0;
}
