/*
[abc152] A - AC or WA
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N, M;

bool solve() { return N == M; }

int main() {
    cin >> N >> M;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
