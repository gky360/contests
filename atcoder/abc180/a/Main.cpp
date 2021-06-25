/*
[abc180] A - box
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N, A, B;

ll solve() { return N - A + B; }

int main() {
    cin >> N >> A >> B;

    cout << solve() << endl;

    return 0;
}
