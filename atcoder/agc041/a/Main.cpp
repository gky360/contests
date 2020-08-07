/*
[agc041] A - Table Tennis Training
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

ll N, A, B;

ll solve() {
    if ((B - A) % 2 == 0) {
        return (B - A) / 2;
    }
    return min((A + B + 1) / 2, (2 * N - A - B - 1) / 2);
}

int main() {
    cin >> N >> A >> B;
    A--, B--;

    cout << solve() << endl;

    return 0;
}
