/*
[abc140] A - Password
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;

ll solve() { return N * N * N; }

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
