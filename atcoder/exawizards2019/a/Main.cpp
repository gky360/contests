/*
[exawizards2019] A - Regular Triangle
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int A, B, C;

bool solve() { return A == B && B == C; }

int main() {
    cin >> A >> B >> C;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
