/*
[abc168] A - ∴ (Therefore)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;

string solve() {
    switch (N % 10) {
        case 2:
        case 4:
        case 5:
        case 7:
        case 9:
            return "hon";
        case 0:
        case 1:
        case 6:
        case 8:
            return "pon";
        default:
            return "bon";
    }
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
